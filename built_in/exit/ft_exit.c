#include "exit.h"

static	void	set_exit_flag(short	flag)
{
	short	*ex;

	ex = ft_return_ptr(NULL, EX_F);
	if (ex)
		*ex = flag;
}

static int	more_arg(char **av, int pec)
{
	if (ft_ban(av[1], "0123456789") != 0)
	{
		ft_printf(STDERR_FILENO, \
		"%oMinishell: exit: %s: numeric argument required\n", NULL, av[1]);
		pec = 255;
		set_exit_flag(1);
	}
	else if (ft_strlen_double(av) >= 3)
	{
		ft_printf(STDERR_FILENO, \
		"%oMinishell: exit: too many arguments\n", NULL);
		set_exit_flag(0);
		pec = 1;
	}
	else
	{
		set_exit_flag(1);
		pec = ft_atoi(av[1]);
	}
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

	pec = 0;
	(void)en;
	(void)re_in;
	(void)re_out;
	tmp = ft_atoi(av[0]);
	if (ft_strlen_double(av) == 1)
	{
		pec = tmp;
		set_exit_flag(1);
	}
	else
		pec = more_arg(av, tmp);
	return (pec);
}
