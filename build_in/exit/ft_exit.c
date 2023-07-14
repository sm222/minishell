#include "exit.h"

int	ft_exit(char **av, int re_in, int re_out)
{
	(void)re_in;
	(void)re_out;
	if (ft_strlen_double(av) > 1)
	{
		ft_putstr_fd("exit don't take args\n", 2);
		return (2);
	}
	exit(ft_atoi(av[0]));
	return (2);
}
