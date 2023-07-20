
#include "cd.h"

static char	*find_home(char **en)
{
	size_t	i;

	i = 0;
	while (en && en[i])
	{
		if (ft_strncmp(en[i], "HOME=", 5) == 0)
			return (en[i] + 5);
		i++;
	}
	return (NULL);
}

/// @brief	try to move in the HOME path
/// @return	2 if fail, or chdir value
static int	get_to_user(char **en)
{
	char	*env;
	char	*tmp;
	int		err;

	env = find_home(en);
	if (!env || !*env)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (2);
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

/// @brief		try to go to char* dir
/// @param	dir	directory
/// @return		err code
static int	goto_dir(char *dir)
{
	int		err;
	char	*tmp;

	err = chdir(dir);
	if (err)
	{
		ft_printf(-1, "%ocd: %s: %s\n", &tmp, sys_errlist[errno], dir);
		ft_putstr_fd(tmp, STDERR_FILENO);
		ft_free(tmp);
		return (EXIT_FAILURE);
	}
	return (err);
}

/// @brief		move to a dir
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
int	ft_cd(char **av, int re_in, int re_out, char **en)
{
	size_t	len;

	(void)re_in;
	(void)re_out;
	len = ft_strlen_double(av);
	if (len == 1)
		return (get_to_user(en));
	else if (len > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (2);
	}
	return (goto_dir(av[1]));
}
