
#include "export.h"

static short	find_word(char *word)
{
	size_t	len;

	len = ft_strlen(word);
	if (len == 0)
		return (FAIL);
	if (ft_isdigit(word[0]) || ft_find(word, BAD_LIST_EXPORT))
	{
		ft_printf(STDERR_FILENO, \
	"%o"MS_NAME" export: `%s': not a valid identifier\n", NULL, word);
		return (FAIL);
	}
	return (SUCCESS);
}

int	look_for_dup(char **env, char *name)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	while (env && env[i])
	{
		len1 = 0;
		len2 = 0;
		while (name[len1] && name[len1] != '=')
			len1++;
		while (env[i][len2] && env[i][len2] != '=')
			len2++;
		if (len2 > len1)
			len1 = len2;
		if (ft_strncmp(env[i], name, len1) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**export_new(char **en, char *arg)
{
	char	**new;
	int		i;
	int		j;

	j = -1;
	if (!en || !arg)
		return (NULL);
	new = NULL;
	i = look_for_dup(en, arg);
	if (i == -1)
	{
		i = ft_strlen_double(en);
		new = ft_calloc(i + 2, sizeof(char *));
		if (!new)
			return (NULL);
		new[i] = ft_strdup(arg);
		while (++j < i)
			new[j] = en[j];
	}
	else
		change_arg_env(en, i, arg);
	return (new);
}

int	ft_export(char **av, int re_in, int re_out, char **en)
{
	size_t	i;
	char	**tmp;

	(void)re_in;
	if (ft_strlen_double(av) == 1)
		return (print_env(en, re_out));
	i = 1;
	while (av && av[i])
	{
		if (find_word(av[i]) == FAIL)
		{
			i++;
			continue ;
		}
		tmp = export_new(en, av[i]);
		if (tmp)
		{
			ft_free(en);
			en = ft_return_ptr(tmp, ENV_C);
			tmp = NULL;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
