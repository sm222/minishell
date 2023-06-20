#include "execution.h"

int	set_pipe(t_cmd **in)
{
	t_cmd	*tmp;

	if (!in || !*in)
		return (debug(BAD_ARGS, "set_pipe", FILE_DEF));
	tmp = (*in);
	if (cmd_node_len(tmp) == 2)
	{
		ft_b_set_flag(&tmp->tok->mode, PIPE_OUT, TRUE);
		ft_b_set_flag(&tmp->next->tok->mode, PIPE_IN, TRUE);
	}
	if (cmd_node_len(tmp) > 2)
	{
		ft_b_set_flag(&tmp->tok->mode, PIPE_OUT, TRUE);
		tmp = tmp->next;
		while (tmp->next)
		{
			ft_b_set_flag(&tmp->tok->mode, PIPE_OUT, TRUE);
			ft_b_set_flag(&tmp->tok->mode, PIPE_IN, TRUE);
			tmp = tmp->next;
		}
		ft_b_set_flag(&tmp->tok->mode, PIPE_IN, TRUE);
	}
	return (SUCCESS);
}

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
	ft_b_print(in->tok->mode, 2);
	if (ft_b_flag_read(in->tok->mode, PIPE_IN) == FALSE && ft_b_flag_read(in->tok->mode, PIPE_OUT) == FALSE)
		return (debug(SUCCESS, "set_redir", FILE_DEF));
	if ((ft_b_flag_read(in->tok->mode, PIPE_IN) == TRUE))
	{
		if (in->prev->pipe[0])
			in->tok->pipe_in = in->prev->pipe[0];
		debug(SUCCESS, "open swich infile", FILE_DEF);
	}
	if ((ft_b_flag_read(in->tok->mode, PIPE_OUT) == TRUE))
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
	if (ft_b_flag_read(in->tok->mode, PIPE_IN) || in->tok->redi_in)
	{
		debug(in->tok->pipe_in, "dup2 in", FILE_DEF);
		if (in->tok->pipe_in)
			debug(dup2(in->tok->pipe_in, STDIN_FILENO), "dup in --", FILE_DEF);
		close(in->tok->pipe_in);
	}
	if (ft_b_flag_read(in->tok->mode, PIPE_OUT) || in->tok->redi_out)
	{
		debug(in->tok->pipe_out, "dup2 out", FILE_DEF);
		if (in->tok->pipe_out)
			debug(dup2(in->tok->pipe_out, STDOUT_FILENO), "dup out --", FILE_DEF);
		close(in->tok->pipe_out);
	}
	return (debug(SUCCESS, "dup_in_out", FILE_DEF));
}
