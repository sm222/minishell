
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
		if (in->in_file)
			dup_err += dup2(in->in_file, STDIN_FILENO);
		if (in->mode)
			dup_err += dup2(in->pipe[1], STDOUT_FILENO);
		ft_printf(2, "%d\n", dup_err);
		run_and_close(in, path);
	}
	else
		wait_make_node_last(wait, pid);
	return (SUCCESS);
}

int	run_cmd(t_cmd **in)
{
	char	**path;
	t_waitp	*wait;
	int		err;
	t_cmd	*tmp;

	wait = NULL;
	path = fr_return_ptr(NULL, PATH);
	if (!in || !*in || !path)
		return (BAD_ARGS);
	tmp = (*in);
	while (tmp)
	{
		if (tmp->buildin == 0)
			err = ft_execution(tmp, &wait, path);
		if (err <= FAIL)
			perror(tmp->command[0]);
		tmp = tmp->next;
	}
	close_all_fd(*in);
	wait_pids(wait, 0);
	return (err);
}