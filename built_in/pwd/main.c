#include "pwd.h"

int	main(int ac, char **av, char **en)
{
	(void)ac;
	av[0] = getcwd(NULL, 0);
	return (ft_pwd(av, 0, 1, en));
}
