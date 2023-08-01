#include "exit.h"

static int	more(char **av, int pec)
{
	short	*ex;

	ex = ft_return_ptr(NULL, EX_F);
	if (ex)
		*ex = 1;
	if (ft_ban(av[1], "0123456789") != 0)
	{
		ft_printf(STDERR_FILENO, \
		"%oMinishell: exit: %s: numeric argument required\n", NULL, av[1]);
		pec = 255;
	}
	else if (ft_strlen_double(av) >= 3)
	{
		ft_printf(STDERR_FILENO, \
		"%oMinishell: exit: too many arguments\n", NULL);
		if (ex)
			*ex = 0;
		pec = 1;
	}
	else
		pec = ft_atoi(av[1]);
	return (pec);
}

/// @brief	use to exit and return a err code
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
int	ft_exit(char **av, int re_in, int re_out, char **en)
{
	unsigned char	pec;
	int				tmp;
	short			*ex_code;

	pec = 0;
	(void)en;
	(void)re_in;
	(void)re_out;
	tmp = ft_atoi(av[0]);
	if (ft_strlen_double(av) == 1)
	{
		pec = tmp;
		ex_code = ft_return_ptr(NULL, EX_F);
		if (ex_code)
			*ex_code = 1;
	}
	else
		pec = more(av, tmp);
	return (pec);
}
