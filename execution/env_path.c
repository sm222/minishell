# include "execution.h"


static short	new_run_env(char ***env, char **old)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (old && old[i])
	{
		if (ft_strchr(old[i], '='))
		{
			(*env)[j] = ft_strdup(old[i]);
			if (!(*env)[j])
				return (M_FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}


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
	new = ft_calloc(j + 1, sizeof(char *));
	if (!new)
	{
		perror("minishell : ft_calloc");
		return (NULL);
	}
	if (new_run_env(&new, en) == M_FAIL)
		new = (char **)ft_double_sfree(((void **)new));
	return (new);
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
