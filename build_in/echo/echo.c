
#include "echo.h"

void	print_loop(char **av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		ft_printf(1, "%s", av[i]);
		if (av[i + 1])
			ft_printf(1, " ");
		i++;
	}
}

int	echo(char **av)
{
	size_t	i;

	i = 0;
	if (ft_strncmp("-n", av[1], 2) == 0)
	{
		i = 1;
		while (av[1][i] && av[1][i] == 'n')
			i++;
		if (av[1][i] == 0)
		{
			print_loop(av + 2);
			return (EX_OK);
		}
	}
	print_loop(av + 1);
	ft_printf(1, "\n");
	return (EX_OK);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf(1, "\n");
		return (0);
	}
	return(echo(av));
}
