#include "execution.h"


int	open_redi_flag(t_cmd *in)
{
	while (in)
	{
		if (in->tok->redi_in)
			ft_b_set_flag(&in->tok->mode, PIPE_IN, TRUE);
		if (in->tok->redi_out)
			ft_b_set_flag(&in->tok->mode, PIPE_OUT, TRUE);
		in = in->next;
	}
	return (SUCCESS);
}


/// @brief use to set the value of the flag in tok 
/// @param in adrres of the 't_cmd' list
/// @return SUCCESS if good, else BAD_ARGS
int	set_pipe(t_cmd **in)
{
	t_cmd	*tmp;

	if (!in || !*in)
		return (BAD_ARGS);
	//	return (debug(BAD_ARGS, "set_pipe", FILE_DEF));
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
	open_redi_flag(*in);
	return (SUCCESS);
}

/// @brief use to set the file in the redirection
/// @param in list link of the 't_cmd'
/// @return SUCCESS, else BAD_ARGS
int	redir_file(t_cmd *in)
{
	if (!in || !in->tok)
		return (BAD_ARGS);
	if (in->tok->redi_in)
		in->tok->pipe_in = in->tok->redi_in;
	if (in->tok->redi_out)
		in->tok->pipe_out = in->tok->redi_out;
	return (SUCCESS);
}

/// @brief 
/// @param in 
/// @return 
int	set_redir(t_cmd *in)
{
	if (!in || !in->tok)
		return (BAD_ARGS);
	ft_b_print(in->tok->mode, 2);
	if (ft_b_flag_read(in->tok->mode, PIPE_IN) == FALSE && \
		ft_b_flag_read(in->tok->mode, PIPE_OUT) == FALSE)
		return (SUCCESS);
	if ((ft_b_flag_read(in->tok->mode, PIPE_IN) == TRUE))
	{
		if (in->prev && in->prev->pipe[0])
			in->tok->pipe_in = in->prev->pipe[0];
	}
	if ((ft_b_flag_read(in->tok->mode, PIPE_OUT) == TRUE))
	{
		if (pipe(in->pipe) != 0)
			return (PIPE_FAIL);
		in->tok->pipe_out = in->pipe[1];
	}
	redir_file(in);
	return (SUCCESS);
}

int	dup_in_out(t_cmd *in)
{
	if (!in || !in->tok)
		return (BAD_ARGS);
	if (ft_b_flag_read(in->tok->mode, PIPE_IN) || in->tok->redi_in)
	{
		if (in->tok->pipe_in)
			dup2(in->tok->pipe_in, STDIN_FILENO);
		close(in->tok->pipe_in);
	}
	if (ft_b_flag_read(in->tok->mode, PIPE_OUT) || in->tok->redi_out)
	{
		if (in->tok->pipe_out)
			dup2(in->tok->pipe_out, STDOUT_FILENO);
		close(in->tok->pipe_out);
	}
	return (SUCCESS);
}
