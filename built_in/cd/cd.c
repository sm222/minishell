
#include "cd.h"
#include "../../include/structure.h"

static char	*find_name(char **en, char *name)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(name);
	while (en && en[i])
	{
		if (ft_strncmp(en[i], name, len) == 0)
			return (en[i] + len);
		i++;
	}
	return (NULL);
}

/// @brief	try to move in the HOME path
/// @return	2 if fail, or chdir value
static int	get_to_user(char **en)
{
	char	*env;
	int		err;

	env = NULL;
	if (en)
		env = find_name(en, "HOME=");
	if (!env || !*env)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (2);
	}
	err = chdir(env);
	if (err)
		ft_printf(STDERR_FILENO, "%ocd: %s: %s\n", \
		NULL, sys_errlist[errno], env);
	return (err);
}

/// @brief		try to go to char* dir
/// @param	dir	directory
/// @return		err code
static int	goto_dir(char *dir)
{
	int	err;

	err = chdir(dir);
	if (err)
	{
		ft_printf(STDERR_FILENO, "%ocd: %s: %s\n", NULL, \
	sys_errlist[errno], dir);
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
