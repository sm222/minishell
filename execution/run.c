
#include "execution.h"
#include "../minishell.h"

int	close_fd(int fd)
{
	if (fd)
		return (close(fd));
	return (0);
}

/// @brief run in all link list of 't_cmd'and close pipe
/// @param in link list
void	close_all_fd(t_cmd *in)
{
	t_cmd	*tmp;

	tmp = in;
	while (tmp)
	{
		close_fd(tmp->pipe[0]);
		close_fd(tmp->pipe[1]);
		close_fd(tmp->tok->redi_in);
		close_fd(tmp->tok->redi_out);
		tmp = tmp->next;
	}
	tmp = in->prev;
	while (tmp)
	{
		close_fd(tmp->pipe[0]);
		close_fd(tmp->pipe[1]);
		close_fd(tmp->tok->redi_in);
		close_fd(tmp->tok->redi_out);
		tmp = tmp->prev;
	}
}

/// @brief use to run the cmd (need to add stuff)
/// @param in t_cmd link list
/// @param path env of system
/// @param cmd relatif path of the cmd ex: /bin/ls
/// @return 
int	run_and_close(t_cmd *in, char **path, char *cmd)
{
	int		err;

	(void)err;
	close_all_fd(in);
	err = execve(cmd, in->command, path);
	perror(path[0]);
	ft_free(cmd);
	exit(1);
	return (FAIL);
}

//
int	free_exe(int err, t_exe *exe)
{
	if (!exe)
		return (BAD_ARGS);
	ft_free(exe->ft_path);
	return (err);
}

/// @brief use to find the cmd and run it
/// @param in 't_cmd' to run
/// @param wait adrres of the 't_waip' list
/// @return FORK_FAIL if fork did't work
/// @return FAIL if can't find a cmd,
/// @return else SUCCESS
short	ft_execution(t_cmd *in, t_waitp **wait)
{
	t_exe		exe;
	t_mshell	*shell;

	shell = fr_return_ptr(NULL, SYS);
	if (!shell || !in || !wait)
		return (BAD_ARGS);
	exe.err = find_path(in->command[0], &exe.ft_path, shell->path);
	if (exe.err == FAIL)
		err_msg(PERROR, exe.err, in->command[0]);
	if (set_redir(in) <= FAIL)
		return (FAIL);
	else if (exe.err == M_FAIL)
		return (M_FAIL);
	exe.pid = fork();
	if (exe.pid == -1)
		return (err_msg(NO_FREE, FORK_FAIL, "fork fail"));
	if (exe.pid == 0)
	{
		dup_in_out(in);
		run_and_close(in, shell->path, exe.ft_path);
	}
	else
		wait_make_node_last(wait, exe.pid);
	ft_free(exe.ft_path);
	return (SUCCESS);
}

int	close_old_fd(t_cmd *in)
{
	if (!in)
		return (BAD_ARGS);
	if (in->prev && in->prev->prev)
	{
		close_fd(in->prev->prev->pipe[0]);
		close_fd(in->prev->prev->pipe[1]);
	}
	return (SUCCESS);
}

/// @brief use after 'cmd_make_node_last'
/// @param in give list of cmd 't_cmd *'
/// @return 
int	run_cmd(t_cmd *in)
{
	int		err;
	t_waitp	*wait;
	t_cmd	*tmp;

	wait = NULL;
	if (!in)
		return (BAD_ARGS);
	tmp = in;
	err = 0;
	set_pipe(&in);
	while (tmp)
	{
		close_old_fd(tmp);
		if (tmp->tok && ft_b_flag_read(tmp->tok->mode, BUILD_IN))
			err = ft_execution_buildin(tmp, &wait);
		else
			err = ft_execution(tmp, &wait);
		if (err < SUCCESS)
			err_msg(PERROR, err, "ft_execution");
		tmp = tmp->next;
	}
	close_all_fd(in);
	wait_pids(wait, 1);
	cmd_free(&in);
	return (SUCCESS);
}
