#include "err.h"
#include "../lib/lib_ft/libft.h"

int	err_msg(short type, int err, char *msg)
{
	if (type == PERROR)
		perror(msg);
	if (type == NO_FREE)
		ft_printf(2, "%s\n", msg);
	if (type == DO_FREE)
		ft_printf(2, "%S\n", msg);
	return(err);
}

int	debug(int err, char *msg, char *file)
{
	int		fd;
	char	*t;

	ft_printf(-1, "%o%d %s\n", &t, err ,msg);
	if (file)
	{
	fd = open(file, O_CREAT | O_APPEND | O_RDWR, 0644);
		if (fd == -1)
		{
			ft_putstr_fd("can't, make debug file\n", 2);
			return (DEBUG_ERR);
		}
		ft_putstr_fd(t, fd);
		close(fd);
	}
	else
		ft_putstr_fd(t, 2);
	ft_free(t);
	return (err);
}
