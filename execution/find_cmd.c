# include "execution.h"

static int	test_local(char *name, char **out)
{
	char	*tmp;

	tmp = NULL;
	if (access(name, X_OK | F_OK) == 0)
	{
		*out = ft_strdup(name);
		if (!*out)
			return (M_FAIL);
		return (1);
	}
	tmp = ft_combine("./%s", name);
	if (!tmp)
		return (M_FAIL);
	if (access(tmp, X_OK | F_OK) == 0)
	{
		*out = tmp;
		return (2);
	}
	return (FAIL);
}

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
		if (access(tmp, X_OK | F_OK) == 0)
		{
			*out = tmp;
			return (i + 2);
		}
		tmp = ft_free(tmp);
	}
	return (FAIL);
}