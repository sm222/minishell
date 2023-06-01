
#include "execution.h"


int	run_cmd(t_cmd *in)
{
	char	*cmd;
	char	**path;
	pid_t	f;

	path = fr_return_ptr(NULL, PATH);
	if (!in || !in->command || !path)
		return (BAD_ARGS);
	find_path(in->command[0], &cmd, path);
	f = fork();
	if (f == 0)
		execve(cmd, in->command, NULL);
	else
		waitpid(f, NULL, 0);
	return (0);
}