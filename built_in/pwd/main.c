#include "pwd.h"

int	main(int ac, char **av, char **en)
{
	(void)ac;
	av[0] = getwd(NULL);
	return (ft_pwd(av, 0, 1, en));
}
