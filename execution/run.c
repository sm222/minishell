
#include "execution.h"
#include "../minishell.h"

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

int	run_and_close(t_cmd *in, char **path, char *cmd)
{
	int		err;

	close_all_fd(in);
	err = execve(cmd, in->command, path);
	return (FAIL);
}



short	ft_execution(t_cmd *in, t_waitp **wait)
{
	int			err;
	char		*ft_path;
	pid_t		pid;
	t_mshell	*shell;

	shell = fr_return_ptr(NULL, SYS);
	if (!shell || pipe(in->pipe) == -1)
		return (FAIL);
	err = find_path(in->command[0], &ft_path, shell->path);
	if (err <= FAIL)
		return (err_msg(PERROR, err, in->command[0]));
	pid = fork();
	if (pid == -1)
		return (err_msg(NO_FREE, FORK_FAIL, "fork fail"));
	if (pid == 0)
	{
		ft_redir(in);
		run_and_close(in, shell->path, ft_path);
	}
	else
		wait_make_node_last(wait, pid);
	ft_free(ft_path);
	return (SUCCESS);
}

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
	while (tmp)
	{
		if (tmp->tok && tmp->tok->build_in == 0)
			err = ft_execution(tmp, &wait);
		else
			err = ft_execution(tmp, &wait);
		tmp = tmp->next;
	}
	close_all_fd(in);
	wait_pids(wait, 1);
	cmd_free(&in);
	return (err);
}