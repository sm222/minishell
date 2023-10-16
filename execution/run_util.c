/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:47 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:25:47 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

short	set_data_exe(t_exe *data, t_mshell *shell, t_cmd *in)
{
	mode_t	err;

	data->ft_path = NULL;
	err = 0;
	if (!data || !shell || !in)
		return (BAD_ARGS);
	data->err_redir = set_redir(in);
	if (!in->command)
		return (1);
	if (data->err_redir < SUCCESS)
		return (data->err_redir);
	data->err = find_path(in->command[0], &data->ft_path, shell->path, &err);
	if (data->err == NO_ASS || data->err == ERR_PD)
		return (permission_denied(in->command[0], &err, data->err));
	else if (data->err == FAIL)
		return (no_file(in->command[0]));
	else if (data->err == ERR_NO_TXT)
		return (126);
	return (SUCCESS);
}

/// @brief	use to close a file descriptor
/// @param	fd	file descriptor
/// @return	0 or the close value
int	close_fd(int fd)
{
	if (fd > 0)
		return (close(fd));
	return (0);
}

/// @brief	run in all link list of 't_cmd'and close pipe
/// @param	in	link list t_cmd* intput
void	close_all_fd(t_cmd *in)
{
	t_cmd	*tmp;

	tmp = in;
	while (tmp)
	{
		if (tmp->tok->redi_in != tmp->tok->redi_doc)
			close_fd(tmp->tok->redi_doc);
		close_fd(tmp->pipe[0]);
		close_fd(tmp->pipe[1]);
		close_fd(tmp->tok->redi_in);
		close_fd(tmp->tok->redi_out);
		tmp = tmp->next;
	}
	tmp = in->prev;
	while (tmp)
	{
		if (tmp->tok->redi_in != tmp->tok->redi_doc)
			close_fd(tmp->tok->redi_doc);
		close_fd(tmp->pipe[0]);
		close_fd(tmp->pipe[1]);
		close_fd(tmp->tok->redi_in);
		close_fd(tmp->tok->redi_out);
		tmp = tmp->prev;
	}
}

/// @brief	use to free t_exe
/// @param	err	err code
/// @param	exe	t_exe* struct
/// @return	BAD_ARGS, or err variable
int	free_exe(int err, t_exe *exe)
{
	if (!exe)
		return (BAD_ARGS);
	ft_free(exe->ft_path);
	return (err);
}

/// @brief	use to close old file descriptor open by pipe
/// @param	in	t_cmd* input
/// @return	BAD_ARGS, SUCCESS
int	close_old_fd(t_cmd *in)
{
	if (!in)
		return (BAD_ARGS);
	if (in->prev && in->prev->prev)
	{
		close_fd(in->prev->prev->pipe[0]);
		close_fd(in->prev->prev->pipe[1]);
	}
	return (SUCCESS);
}
