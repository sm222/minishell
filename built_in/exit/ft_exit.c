#include "exit.h"
/*
static int	look_args(char **av, int *pec)
{
	
}
*/


static int	more(char **av, int *pec)
{
	if (ft_ban(av[1], "0123456789") != 0)
	{
		ft_printf(STDERR_FILENO, \
		"%oMinishell: exit: %s: numeric argument required\n", NULL, av[1]);
		*pec = 255;
	}
	//else if (ft_strlen_double(av) => 2)
	//	*pec = look_args(av, pec);
	return (*pec);
}


/// @brief	use to exit and return a err code
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
int	ft_exit(char **av, int re_in, int re_out, char **en)
{
	unsigned char	pec;
	int				*tmp;

	pec = 0;
	(void)en;
	(void)re_in;
	(void)re_out;
	tmp = ft_return_ptr(NULL, PEC);
	if (ft_strlen_double(av) == 1)
	{
		if (!tmp)
			return (2);
		pec = *tmp;
	}
	else
		pec = more(av, tmp);
	return (pec);
}
