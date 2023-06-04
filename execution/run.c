
#include "execution.h"

void	close_all_fd(t_cmd *in)
{
	t_cmd	*tmp;

	tmp = in;
	while (tmp)
	{
		close(tmp->pipe[0]);
		close(tmp->pipe[1]);
		close(tmp->in_file);
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

	out = NULL;
	close_all_fd(in);
	if (find_path(in->command[0], &out, path) <= FAIL)
	{
		perror(in->command[0]);
		return (FAIL);
	}
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
	dup_err += dup2(in->in_file, STDIN_FILENO);
	if (in->next)
		dup_err += dup2(in->pipe[1], STDOUT_FILENO);
	pid = fork();
	if (pid == -1)
		return (FORK_FAIL);
	if (pid == 0)
		run_and_close(in, path);
	else
		wait_make_node_last(wait, pid);
	return (SUCCESS);
}

int	run_cmd(t_cmd *in)
{
	char	**path;
	t_waitp	*wait;
	int		err;

	wait = NULL;
	path = fr_return_ptr(NULL, PATH);
	if (!in || !in->command || !path)
		return (BAD_ARGS);
	while (in)
	{
		if (in->buildin == 0)
			err = ft_execution(in, &wait, path);
		if (err <= FAIL)
			perror(in->command[0]);
		in = in->next;
	}
	wait_pids(wait, 1);
	return (err);
}