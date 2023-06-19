#include "execution.h"

int	redir_file(t_cmd *in)
{
	if (!in || !in->tok)
		return(debug(BAD_ARGS, "redir_file", FILE_DEF));
	if (in->tok->redi_in)
		in->tok->pipe_in = in->tok->redi_in;
	if (in->tok->redi_out)
		in->tok->pipe_out = in->tok->redi_out;
	return (SUCCESS);
}

int	set_redir(t_cmd *in)
{
	if (!in || !in->tok)
		return(debug(BAD_ARGS, "set_redir", FILE_DEF));
	if (in->tok->mode == PIPE_NO && !in->tok->redi_in && !in->tok->redi_out)
		return (debug(SUCCESS, "set_redir", FILE_DEF));
	if (in->tok->mode == PIPE_IN || in->tok->mode == PIPE_IN_OUT)
	{
		if (in->prev->pipe[0])
			in->tok->pipe_in = in->prev->pipe[0];
		debug(SUCCESS, "open swich infile", FILE_DEF);
	}
	if (in->tok->mode == PIPE_OUT || in->tok->mode == PIPE_IN_OUT)
	{
		if (pipe(in->pipe) != 0)
			return (debug(PIPE_FAIL, "set_redir", FILE_DEF));
		debug(SUCCESS, "open pipe", FILE_DEF);
		in->tok->pipe_out = in->pipe[1];
	}
	redir_file(in);
	return (debug(SUCCESS, "set_redir", FILE_DEF));
}

int	dup_in_out(t_cmd *in)
{
	if (!in || !in->tok)
		return (debug(BAD_ARGS, "dup_in_out", FILE_DEF));
	if (in->tok->mode == PIPE_IN || in->tok->mode == PIPE_IN_OUT || in->tok->redi_in)
	{
		debug(in->tok->pipe_in, "dup2 in", FILE_DEF);
		if (in->tok->pipe_in)
			debug(dup2(in->tok->pipe_in, STDIN_FILENO), "dup in --", FILE_DEF);
		close(in->tok->pipe_in);
	}
	if (in->tok->mode == PIPE_OUT || in->tok->mode == PIPE_IN_OUT || in->tok->redi_out)
	{
		debug(in->tok->pipe_out, "dup2 out", FILE_DEF);
		if (in->tok->pipe_out)
			debug(dup2(in->tok->pipe_out, STDOUT_FILENO), "dup out --", FILE_DEF);
		close(in->tok->pipe_out);
	}
	return (debug(SUCCESS, "dup_in_out", FILE_DEF));
}
