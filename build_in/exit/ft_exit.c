#include "exit.h"

/// @brief	use to exit and return a err code
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
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
