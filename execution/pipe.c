#include "execution.h"

int	swich_redir(t_cmd *in)
{
	if (!in)
		return(debug(BAD_ARGS, "swich_redir", FILE_DEF));
	if (in->tok->mode == PIPE_NO)
		return (debug(SUCCESS, "swich_redir", FILE_DEF));
	if (in->tok->mode == PIPE_IN || in->tok->mode == PIPE_IN_OUT)
	{
		if (in->prev->pipe[0])
			in->tok->pipe_in = in->prev->pipe[0];
		debug(SUCCESS, "open swich infile", FILE_DEF);
	}
	if (in->tok->mode == PIPE_OUT || in->tok->mode == PIPE_IN_OUT)
	{
		if (pipe(in->pipe) != 0)
			return (debug(PIPE_FAIL, "swich_redir", FILE_DEF));
		debug(SUCCESS, "open pipe", FILE_DEF);
		in->tok->pipe_out = in->pipe[1];
	}
	return (debug(SUCCESS, "swich_redir", FILE_DEF));
}

int	ft_redir(t_cmd *in)
{
	if (!in || !in->tok)
		return (debug(BAD_ARGS, "ft_redir", FILE_DEF));
	if (in->tok->mode == PIPE_IN || in->tok->mode == PIPE_IN_OUT)
	{
		debug(in->tok->pipe_in, "dup2 in", FILE_DEF);
		if (in->tok->pipe_in)
			debug(dup2(in->tok->pipe_in, STDIN_FILENO), "dup in --", FILE_DEF);
		close(in->tok->pipe_in);
	}
	if (in->tok->mode == PIPE_OUT || in->tok->mode == PIPE_IN_OUT)
	{
		debug(in->tok->pipe_out, "dup2 out", FILE_DEF);
		if (in->tok->pipe_out)
			debug(dup2(in->tok->pipe_out, STDOUT_FILENO), "dup out --", FILE_DEF);
		close(in->tok->pipe_out);
	}
	return (debug(SUCCESS, "ft_redir", FILE_DEF));
}
