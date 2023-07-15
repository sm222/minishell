#include "execution.h"

/// @brief	use to close a file descriptor
/// @param	fd	file descriptor
/// @return	0 or the close value
int	close_fd(int fd)
{
	if (fd)
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
