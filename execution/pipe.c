/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:38 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/25 18:14:26 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

/// @brief	look if the is redirection need to be open
/// @param	in	t_cmd* input
/// @return	SUCCESS
int	open_redi_flag(t_cmd *in)
{
	if (!in || !in->tok)
		return (BAD_ARGS);
	while (in)
	{
		if (in->tok->redi_in)
			ft_b_set_flag(&in->tok->mode, PIPE_IN, true);
		if (in->tok->redi_out)
			ft_b_set_flag(&in->tok->mode, PIPE_OUT, true);
		in = in->next;
	}
	return (SUCCESS);
}

/// @brief	use to set the value of the flag in tok 
/// @param	in	adrres of the 't_cmd' list
/// @return	SUCCESS if good, else BAD_ARGS
int	set_pipe(t_cmd **in)
{
	t_cmd	*tmp;

	if (!in || !*in)
		return (BAD_ARGS);
	tmp = (*in);
	if (cmd_node_len(tmp) == 2)
	{
		ft_b_set_flag(&tmp->tok->mode, PIPE_OUT, true);
		ft_b_set_flag(&tmp->next->tok->mode, PIPE_IN, true);
	}
	if (cmd_node_len(tmp) > 2)
	{
		ft_b_set_flag(&tmp->tok->mode, PIPE_OUT, true);
		tmp = tmp->next;
		while (tmp->next)
		{
			ft_b_set_flag(&tmp->tok->mode, PIPE_OUT, true);
			ft_b_set_flag(&tmp->tok->mode, PIPE_IN, true);
			tmp = tmp->next;
		}
		ft_b_set_flag(&tmp->tok->mode, PIPE_IN, true);
	}
	open_redi_flag(*in);
	return (SUCCESS);
}

/// @brief	use to set the file in the redirection
/// @param	in	list link of the 't_cmd'
/// @return	SUCCESS, else BAD_ARGS
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

/// @brief	use to swich the the in and out
/// @param	in	input t_cmd*
/// @return	BAD_ARGS, PIPE_FAIL, SUCCESS
int	set_redir(t_cmd *in)
{
	if (!in || !in->tok)
		return (BAD_ARGS);
	if (ft_b_flag_read(in->tok->mode, PIPE_IN) == false && \
		ft_b_flag_read(in->tok->mode, PIPE_OUT) == false)
		return (SUCCESS);
	if ((ft_b_flag_read(in->tok->mode, PIPE_IN) == true))
	{
		if (in->prev && in->prev->pipe[0])
			in->tok->pipe_in = in->prev->pipe[0];
	}
	if ((ft_b_flag_read(in->tok->mode, PIPE_OUT) == true))
	{
		if (pipe(in->pipe) != 0)
			return (PIPE_FAIL);
		in->tok->pipe_out = in->pipe[1];
	}
	redir_file(in);
	return (SUCCESS);
}

/// @brief	use the dup fonction to change the in and out
/// @param	in	t_cmd* input
/// @return	BAD_ARGS, SUCCESS
int	dup_in_out(t_cmd *in)
{
	if (!in || !in->tok)
		return (BAD_ARGS);
	if (ft_b_flag_read(in->tok->mode, PIPE_IN) || in->tok->redi_in)
	{
		if (in->tok->pipe_in)
			dup2(in->tok->pipe_in, STDIN_FILENO);
		close_fd(in->tok->pipe_in);
	}
	if (ft_b_flag_read(in->tok->mode, PIPE_OUT) || in->tok->redi_out)
	{
		if (in->tok->pipe_out)
			dup2(in->tok->pipe_out, STDOUT_FILENO);
		close_fd(in->tok->pipe_out);
	}
	return (SUCCESS);
}
