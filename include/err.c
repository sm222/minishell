#include "err.h"

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