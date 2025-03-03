
#include "pwd.h"

int	main(int ac, char **av, char **en)
{
	char	pwd[PATH_MAX + 1];

	(void)ac;
	ft_bzero(pwd, PATH_MAX + 1);
	getcwd(pwd, PATH_MAX);
	av[0] = pwd;
	return (ft_pwd(av, 0, 1, en));
}
