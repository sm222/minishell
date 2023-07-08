#include "exit.h"

int	ft_exit(char **av, int re_in, int re_out)
{
	int	*pec;

	(void)re_in;
	(void)re_out;
	if (ft_strlen_double(av) > 1)
	{
		ft_putstr_fd("exit don't args\n", 2);
		return (2);
	}
	pec = fr_return_ptr(NULL, PEC);
	if (!pec)
	{
		ft_putstr_fd("exit call out of shell\n", 2);
		exit(2);
	}
	exit(*pec);
	return (0);
}
