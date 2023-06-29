
#include "cd.h"

static int	get_to_use(void)
{
	char	*env;
	char	*tmp;
	int		err;

	env = getenv("HOME");
	if (!env)
	{
		ft_putstr_fd("cd: HOME not set\n",2);
		return (1);
	}
	err = chdir(env);
	if (err)
	{
		ft_printf(-1, "%ocd : %s :%s", &tmp, sys_errlist[errno], env);
		ft_putstr_fd(tmp, STDERR_FILENO);
	}
	return (err);
}

/*
static int	goto_dir(char *dir)
{

}
*/

int	ft_cd(char **av, int re_in, int re_out)
{
	size_t	len;

	(void)re_in;
	(void)re_out;
	len = ft_strlen_double(av);
	if (len == 1)
	{
		printf("%d\n", get_to_use());
	}
	else
	{
		if (chdir(av[1]))
			return (0);
	}
	return (0);
}
