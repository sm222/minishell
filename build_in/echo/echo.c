
#include "echo.h"

/// @brief	use to print every argv
/// @param	av	argv
/// @param	i	index to start
/// @param	fd	file descriptor
void	print_loop(char **av, size_t i, int fd)
{
	size_t	len;

	len = ft_strlen_double(av);
	while (i < len)
	{
		ft_putstr_fd(av[i], fd);
		if (av[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
}

/// @brief	use to skip -n
/// @param	av	argv
/// @return	index
size_t	skip_args(char **av)
{
	size_t	tmp;
	size_t	i;

	tmp = 1;
	if (!av[1])
		return (0);
	while (av[tmp] && ft_strncmp("-n", av[tmp], 2) == 0)
	{
		i = 2;
		while (av[tmp][i] && av[tmp][i] == 'n')
			i++;
		if (av[tmp][i] == '\0')
			tmp++;
		else
			break ;
	}
	return (tmp);
}

/// @brief	use to print args
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
int	ft_echo(char **av, int re_in, int re_out)
{
	size_t	i;

	(void)re_in;
	i = skip_args(av);
	if (i == 0)
	{
		ft_putchar_fd('\n', re_out);
		return (EX_OK);
	}
	print_loop(av, i, re_out);
	if (i == 1)
		ft_putchar_fd('\n', re_out);
	return (EX_OK);
}
