
#include "execution.h"

void	close_all_fd(t_cmd *in)
{
	t_cmd	*tmp;

	tmp = in;
	while (tmp)
	{
		ft_printf(2, "%d > %d\n", tmp->pipe[0] ,close(tmp->pipe[0]));
		ft_printf(2, "%d > %d\n", tmp->pipe[1] ,close(tmp->pipe[1]));
		tmp = tmp->next;
	}
	tmp = in->prev;
	while (tmp)
	{
		ft_printf(2, "%d > %d\n", tmp->pipe[0] ,close(tmp->pipe[0]));
		ft_printf(2, "%d > %d\n", tmp->pipe[1] ,close(tmp->pipe[1]));
		tmp = tmp->prev;
	}
}


int	run_and_close(t_cmd *in, char **path)
{
	char	*out;
	int		err;

	out = NULL;
	close_all_fd(in);
	err = find_path(in->command[0], &out, path);
	if (err <= FAIL)
	{
		if (err == FAIL)
			perror(in->command[0]);
		else
			ft_printf(2, "MALLOC FAIL\n");
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
	if (in->prev)
	{
		dup_err += dup2(in->prev->pipe[0], STDIN_FILENO);
		ft_putendl_fd("here", 2);
	}
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
		ft_printf(2, "%s\n", in->command[0]);
		if (in->buildin == 0)
			err = ft_execution(in, &wait, path);
		if (err <= FAIL)
			perror(in->command[0]);
		in = in->next;
	}
	ft_printf(2, "ici\n");
	wait_pids(wait, 0);
	return (err);
}