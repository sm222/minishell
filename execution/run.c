
#include "execution.h"

short	ft_execution(t_cmd *in)
{
	(void)in;
	return (0);
}

int	run_cmd(t_cmd *in)
{
	char	*cmd;
	char	**path;
	t_waitp	*wait;
	int		err;

	wait = NULL;
	path = fr_return_ptr(NULL, PATH);
	if (!in || !in->command || !path)
		return (BAD_ARGS);
	while (in)
	{
		err = find_path(in->command[0], &cmd, path);
		if (err == FAIL)
		{
			perror(in->command[0]);
			in = in->next;
			continue ;
		}
	}
	wait_pids(wait, 1);
	return (0);
}