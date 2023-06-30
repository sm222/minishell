
#include "cd.h"

static int	get_to_user(void)
{
	char	*env;
	char	*tmp;
	int		err;

	env = getenv("HOME");
	if (!env || !*env)
	{
		ft_putstr_fd(env, 2);
		ft_putstr_fd("rr\n", 2);
		ft_putstr_fd("cd: HOME not set\n",2);
		return (1);
	}
	err = chdir(env);
	if (err)
	{
		ft_printf(-1, "%ocd: %s: %s\n", &tmp, sys_errlist[errno], env);
		ft_putstr_fd(tmp, STDERR_FILENO);
		ft_free(tmp);
	}
	return (err);
}

static int	goto_dir(char *dir)
{
	int	err;
	char	*tmp;

	err = chdir(dir);
	if (err)
	{
		ft_printf(-1, "%ocd: %s: %s\n", &tmp, sys_errlist[errno], dir);
		ft_putstr_fd(tmp, STDERR_FILENO);
		ft_free(tmp);
		exit(EXIT_FAILURE);
	}
	return(err);
}


int	ft_cd(char **av, int re_in, int re_out)
{
	size_t	len;

	(void)re_in;
	(void)re_out;
	len = ft_strlen_double(av);
	if (len == 1)
		return (get_to_user());
	return (goto_dir(av[1]));
}
