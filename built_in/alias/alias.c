
#include "alias.h"

static short	look_new_arg(char *old, char *new)
{
	if (ft_strchr(old, '=') && !ft_strchr(new, '='))
		return (0);
	return (1);
}

static short	find_word(char *word, int *pec)
{
	size_t	len;
	short	err;
	char	*test;

	err = SUCCESS;
	len = 0;
	while (word[len] && word[len] != '=')
		len++;
	test = ft_strncpy(word, len);
	if (ft_strlen(word) == 0 || ft_isdigit(word[0]) || \
		ft_find(test, BAD_LIST_EXPORT))
	{
		ft_printf(STDERR_FILENO, \
	"%oalias: `%s': not a valid identifier\n", NULL, word);
		*pec = 1;
		err = FAIL;
	}
	ft_free(test);
	return (err);
}

static int	look_for_dup(char **env, char *name)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	if (!name)
		return (-1);
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

static char	**change_arg_env(char **en, int i, char *new)
{
	char	*tmp;

	if (!look_new_arg(en[i], new))
		return (en);
	tmp = ft_strdup(new);
	if (tmp)
	{
		ft_free(en[i]);
		en[i] = tmp;
	}
	return (en);
}

char	**alias_new(char **en, char *arg)
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

static int	print_alias(char **data, int fd)
{
	size_t	i;

	i = 0;
	if (!data)
		return (1);
	while (data[i])
	{
		ft_printf(fd, "%o%s\n", NULL, data[i]);
		i++;
	}
	return (0);
}

int	ft_alias(char **av, int re_in, int re_out, char **en)
{
	int		err;
	size_t	i;
	size_t	len;
	char	**alias;
	char	**tmp;

	(void)re_in;
	(void)en;
	err = 0;
	i = 1;
	alias = ft_return_ptr(NULL, ALIAS_VAR);
	len = ft_strlen_double(av);
	if (len == 1)
		return (print_alias(alias, re_out));
	while (i < len)
	{
		if (find_word(av[i], &err) == FAIL)
		{
			i++;
			continue ;
		}
		tmp = alias_new(alias, av[i]);
		if (tmp)
		{
			ft_free(alias);
			alias = ft_return_ptr(tmp, ALIAS_VAR);
		}
		i++;
	}
	return (err);
}
