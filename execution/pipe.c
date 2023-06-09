#include "execution.h"

void	swich_redir(int mode, )
{
	if ()
}

int	ft_redir(t_cmd *in)
{
	if (!in || !in->tok)
		return (BAD_ARGS);
	if (in->tok->pipe_in > -1)
		dup2(in->tok->pipe_in, STDIN_FILENO);
	if (in->tok->pipe_out > -1)
		dup2(in->tok->pipe_out, STDOUT_FILENO);
	return (SUCCESS);
}
