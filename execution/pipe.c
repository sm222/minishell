#include "execution.h"

int	swich_redir(t_cmd *in)
{
	if (in->tok->mode == PIPE_NO)
		return (debug(SUCCESS, "swich_redir"));
	if (in->tok->mode >= PIPE_IN)
		in->tok->pipe_in = in->prev->pipe[0];
	if (in->tok->mode >= PIPE_OUT)
	{
		if (pipe(in->pipe) != 0)
			return (debug(PIPE_FAIL, "swich_redir"));
		in->tok->pipe_out = in->pipe[1];
	}
	return (debug(SUCCESS, "swich_redir"));
}

int	ft_redir(t_cmd *in)
{
	if (!in || !in->tok)
		return (debug(BAD_ARGS, "ft_redir"));
	if (swich_redir(in))
		return (FAIL);
	if (in->tok->pipe_in > -1)
		dup2(in->tok->pipe_in, STDIN_FILENO);
	if (in->tok->pipe_out > -1)
		dup2(in->tok->pipe_out, STDOUT_FILENO);
	return (SUCCESS);
}
