
#include "execution.h"


int	run_cmd(t_cmd *in)
{
	char	*cmd;
	char	**path;

	path = NULL;
	if (!in || !in->command)
		return (BAD_ARGS);
	find_path(in->command[0], &cmd, path);
	return (0);
}