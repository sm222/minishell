#include "execution.h"

short	set_data_exe(t_exe *data, t_mshell *shell, t_cmd *in)
{
	mode_t	err;

	err = 0;
	if (!data || !shell || !in)
		return (BAD_ARGS);
	data->err_redir = set_redir(in);
	if (data->err_redir < SUCCESS)
		return (data->err_redir);
	data->err = find_path(in->command[0], &data->ft_path, shell->path, &err);
	if (data->err == NO_ASS)
		return (permission_denied(in->command[0], &err));
	else if (data->err == FAIL)
		return (no_file(in->command[0]));
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
		close_fd(tmp->pipe[0]);
		close_fd(tmp->pipe[1]);
		close_fd(tmp->tok->redi_in);
		close_fd(tmp->tok->redi_out);
		tmp = tmp->next;
	}
	tmp = in->prev;
	while (tmp)
	{
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
