# include "execution.h"

/// @brief try to find the file in local folder
/// @param name of the fontion
/// @param out return the path with name of the fontion
/// @return 1 if local, 2 if ./ fail FAIL, else M_FAIL
/// @ref
static int	test_local(char *name, char **out)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_combine("./%s", name);
	if (!tmp)
		return (M_FAIL);
	if (access(tmp, F_OK | X_OK) == 0)
	{
		*out = tmp;
		return (2);
	}
	if (access(name, F_OK | X_OK) == 0)
	{
		*out = ft_strdup(name);
		if (!*out)
			return (M_FAIL);
		return (1);
	}
	return (FAIL);
}

/// @brief try to find the cmd
/// @param name name of the cmd
/// @param out return name + path, NULL if fail
/// @param list path of the system
/// @return -1 if M_FAIL, FAIL if can't find path
/// @return else return 1 or 2 for local file, 3 and plus for the index were it find it 
int	find_path(char *name, char **out, char **list)
{
	char	*tmp;
	int		local;
	size_t	i;

	i = 0;
	tmp = NULL;
	*out = NULL;
	local = test_local(name, out);
	if (local > 0 || local == M_FAIL)
		return (local);
	while (list[i])
	{
		tmp = ft_combine("%s/%s", list[i], name);
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