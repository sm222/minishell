
#include "env.h"

int	ft_env(char **av, int re_in, int re_out)
{
	size_t	i;

	(void)re_in;
	i = 0;
	if (!av)
	{
		ft_putstr_fd("env: too many arguments\n",2);
		return (2);
	}
	while (av && av[i])
	{
		ft_putstr_fd(av[i++] ,re_out);
		ft_putchar_fd('\n', re_out);
	}
	return (0);
}
