#include "exit.h"


static int	local(char **av)
{
	int	code;

	code = 1;
	if (ft_strlen_double(av) == 2)
	{
		if (ft_ban(av[1], "0123456789") != 0)
		{
			ft_printf(STDERR_FILENO, \
			"%oMinishell: exit: %s: numeric argument required\n", NULL, av[1]);
			code = 0;
		}
	}
	return (code);
}

/// @brief	use to exit and return a err code
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
int	ft_exit(char **av, int re_in, int re_out, char **en)
{
	(void)en;
	(void)re_out;
	if (re_in == -1)
		return(local(av));
	return (0);
}
