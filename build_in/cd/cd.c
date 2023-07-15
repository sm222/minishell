
#include "cd.h"

/// @brief	try to move in the HOME path
/// @return	2 if fail, or chdir value
static int	get_to_user(void)
{
	char	*env;
	char	*tmp;
	int		err;

	env = getenv("HOME");
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
int	ft_cd(char **av, int re_in, int re_out)
{
	size_t	len;

	(void)re_in;
	(void)re_out;
	len = ft_strlen_double(av);
	if (len == 1)
		return (get_to_user());
	else if (len > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (2);
	}
	return (goto_dir(av[1]));
}
