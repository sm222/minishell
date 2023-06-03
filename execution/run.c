
#include "execution.h"

int	run_and_close()

short	ft_execution(t_cmd *in, t_waitp **wait, char **path)
{
	int		dup_err;
	char	*out;
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
	out = NULL;
	if (pid == 0)

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
			err = ft_execution(in, &wait);
		if (err <= FAIL)
			perror(in->command[0]);
		in = in->next;
	}
	wait_pids(wait, 1);
	return (err);
}