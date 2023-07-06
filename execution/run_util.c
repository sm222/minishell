#include "execution.h"

int	close_fd(int fd)
{
	if (fd)
		return (close(fd));
	return (0);
}

/// @brief run in all link list of 't_cmd'and close pipe
/// @param in link list
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

int	free_exe(int err, t_exe *exe)
{
	if (!exe)
		return (BAD_ARGS);
	ft_free(exe->ft_path);
	return (err);
}

/// @brief 
/// @param in 
/// @return 
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