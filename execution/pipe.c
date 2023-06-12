#include "execution.h"

int	swich_redir(t_cmd *in)
{
	if (!in)
		return(debug(BAD_ARGS, "swich_redir"));
	if (in->tok->mode == PIPE_NO)
		return (debug(SUCCESS, "swich_redir"));
	if (in->tok->mode == PIPE_IN || in->tok->mode == PIPE_IN_OUT)
	{
		in->tok->pipe_in = in->prev->pipe[0];
		debug(SUCCESS, "open swich infile");
	}
	if (in->tok->mode == PIPE_OUT || in->tok->mode == PIPE_IN_OUT)
	{
		if (pipe(in->pipe) != 0)
			return (debug(PIPE_FAIL, "swich_redir"));
		debug(SUCCESS, "open pipe");
		in->tok->pipe_out = in->pipe[1];
	}
	return (debug(SUCCESS, "swich_redir"));
}

int	ft_redir(t_cmd *in)
{
	if (!in || !in->tok)
		return (debug(BAD_ARGS, "ft_redir"));
	if (in->tok->mode == PIPE_IN || in->tok->mode == PIPE_IN_OUT)
	{
		debug(in->tok->pipe_in, "dup2 in");
		debug(dup2(in->tok->pipe_in, STDIN_FILENO), "dup in --");
		perror("pipe in");
	}
	if (in->tok->mode == PIPE_OUT || in->tok->mode == PIPE_IN_OUT)
	{
		debug(in->tok->pipe_out, "dup2 out");
		debug(dup2(in->tok->pipe_out, STDOUT_FILENO), "dup out --");
		perror("pipe out");
	}
	return (debug(SUCCESS, "ft_redir"));
}
