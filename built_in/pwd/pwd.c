#include "pwd.h"

/// @brief	
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
int	ft_pwd(char **av, int re_in, int re_out, char **en)
{
	(void)re_in;
	(void)en;
	if (ft_strlen_double(av) > 1)
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	else
		ft_printf(re_out, "%o%s\n", NULL, av[0]);
	return (EXIT_SUCCESS);
}
