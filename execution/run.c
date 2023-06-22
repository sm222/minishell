
#include "execution.h"
#include "../minishell.h"

/// @brief run in all link list of 't_cmd'and close pipe
/// @param in link list
void	close_all_fd(t_cmd *in)
{
	t_cmd	*tmp;

	tmp = in;
	while (tmp)
	{
		if (tmp->pipe[0])
			close(tmp->pipe[0]);
		if (tmp->pipe[1])
			close(tmp->pipe[1]);
		tmp = tmp->next;
	}
	tmp = in->prev;
	while (tmp)
	{
		if (tmp->pipe[0])
			close(tmp->pipe[0]);
		if (tmp->pipe[1])
			close(tmp->pipe[1]);
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
	exit(1); //meaby rm later
	return (FAIL);
}

//
int	free_exe(int err, t_exe *exe)
{
	if (!exe)
		return (debug(BAD_ARGS,"bad args in free_exe", FILE_DEF));
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
		return (debug(BAD_ARGS,"bad args in ft_execution", FILE_DEF));
	exe.err = find_path(in->command[0], &exe.ft_path, shell->path);
	if (exe.err == FAIL)
		err_msg(PERROR, exe.err, in->command[0]);
	if (set_redir(in) <= FAIL)
		return (debug(FAIL, "ft_redir", FILE_DEF));
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
		debug(0, "--cmd--", FILE_DEF);
		if (tmp->tok && ft_b_flag_read(tmp->tok->mode, BUILD_IN))
			err = ft_execution(tmp, &wait);
		else
			err = ft_execution(tmp, &wait);
		debug(err, "run_cmd", FILE_DEF);
		tmp = tmp->next;
	}
	close_all_fd(in);
	wait_pids(wait, 1);
	cmd_free(&in);
	return (SUCCESS);
}
