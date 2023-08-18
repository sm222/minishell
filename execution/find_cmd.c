# include "execution.h"


/// @brief	try to find the file in local folder
/// @param	name	of the fontion
/// @param	out		return the path with name of the fontion
/// @return	1 if local, 2 if ./ fail FAIL, else M_FAIL
static int	test_local(char *name, char **out,  mode_t *err)
{
	struct stat	test;

	lstat(name, &test);
	ft_printf(2, "%oici%d\n", NULL , S_ISREG(test.st_mode));
	*err = test.st_mode;
	if (access(name, X_OK | F_OK) == 0)
	{
		if (S_ISDIR(test.st_mode) || S_ISLNK(test.st_mode))
			return (NO_ASS);
		*out = ft_strdup(name);
		if (!*out)
			return (M_FAIL);
		return (1);
	}
	perror("ici ici ici");
	return (FAIL);
}

/// @brief	try to find the cmd
/// @param	name	name of the cmd
/// @param	out		return name + path, NULL if fail
/// @param	list	path of the system
/// @return	-1 if M_FAIL, FAIL if can't find path
/// @return	else return 1 or 2 for local file,
/// @return	3 and plus for the index were it find it
int	find_path(char *name, char **out, char **list, mode_t *err)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	*out = NULL;
	if (name && (name[0] == '.' || name[0] == '/'))
		return (test_local(name, out, err));
	while (list && list[i])
	{
		ft_printf(NO_PRINT, "%o%s/%s", &tmp, list[i], name);
		if (!tmp)
			return (M_FAIL);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			*out = tmp;
			return (i + 2);
		}
		tmp = ft_free(tmp);
		i++;
	}
	return (FAIL);
}
