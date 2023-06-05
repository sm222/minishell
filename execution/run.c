
#include "execution.h"

void	close_all_fd(t_cmd *in)
{
	t_cmd	*tmp;

	tmp = in;
	while (tmp)
	{
		close(tmp->pipe[0]);
		close(tmp->pipe[1]);
		tmp = tmp->next;
	}
	tmp = in->prev;
	while (tmp)
	{
		close(tmp->pipe[0]);
		close(tmp->pipe[1]);
		tmp = tmp->prev;
	}
}

int	run_and_close(t_cmd *in, char **path)
{
	char	*out;
	int		err;

	out = NULL;
	err = find_path(in->command[0], &out, path);
	if (err <= FAIL)
	{
		if (err == FAIL)
			perror(in->command[0]);
		else
			ft_printf(2, "MALLOC FAIL\n");
		return (FAIL);
	}
	close_all_fd(in);
	execve(out, in->command, path);
	return (FAIL);
}



short	ft_execution(t_cmd *in, t_waitp **wait, char **path)
{
	int		dup_err;
	pid_t	pid;

	dup_err = 0;
	if (pipe(in->pipe) == -1)
		return (FAIL);
	pid = fork();
	if (pid == -1)
		return (FORK_FAIL);
	if (pid == 0)
	{
		run_and_close(in, path);
	}
	else
		wait_make_node_last(wait, pid);
	return (SUCCESS);
}

int	run_cmd(t_cmd *in)
{
	char	**path;
	int		err;
	t_waitp	*wait;
	t_cmd	*tmp;

	wait = NULL;
	path = fr_return_ptr(NULL, PATH);
	if (!in || !path)
		return (BAD_ARGS);
	tmp = in;
	while (tmp)
	{
		err = 0;
		if (tmp->tok && tmp->tok->build_in == 0)
			err = ft_execution(tmp, &wait, path);
		else
		{
			tmp = tmp->next;
			continue ;
		}
		if (err <= FAIL)
			perror(tmp->command[0]);
		tmp = tmp->next;
	}
	close_all_fd(in);
	wait_pids(wait, 1);
	cmd_free(&in);
	return (err);
}