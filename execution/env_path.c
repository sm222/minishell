# include "execution.h"

char	**ex_en_new(char **en)
{
	char	**new;
	size_t	i;
	size_t	j;

	(void)new;
	new = NULL;
	i = 0;
	j = 0;
	while (en && en[i])
	{
		if (ft_strchr(en[i], '='))
			j++;
		i++;
	}
	ft_printf(2, "%d\n", j);
	return (NULL);
}

short	make_new_path(t_mshell *shell)
{
	size_t	i;

	if (!shell)
		return (BAD_ARGS);
	if (shell->path)
		shell->path = (char **)ft_double_sfree((void **)shell->path);
	i = 0;
	while (shell->en && shell->en[i])
	{
		if (ft_strncmp("PATH=", shell->en[i], 5) == 0)
		{
			shell->path = ft_split(shell->en[i] + 5, ':');
			if (!shell->path)
				return (M_FAIL);
			return (SUCCESS);
		}
		i++;
	}
	shell->path = ft_split(" : ", ':');
	if (!shell->path)
		return (M_FAIL);
	return (SUCCESS);
}
