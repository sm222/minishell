#include "unset.h"

static short	find_word(char **list, char *word)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(word);
	if (len == 0)
		return (FAIL);
	if (ft_isdigit(word[0]))
	{
		ft_printf(-1, "%o"MS_NAME" unset: `%s': not a valid identifier\n", &tmp, word);
		ft_putstr_fd(tmp, 2);
		ft_free(tmp);
	}
	while (list && list[i])
	{
		if (ft_strncmp(list[i], word, len) == 0 && list[i][len] == '=')
			return (SUCCESS);
		i++;
	}
	return (FAIL);
}

static short	new_arg(char **new, char **old, char *skip)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!new || !old || !skip)
		return (BAD_ARGS);
	i = 0;
	j = 0;
	len = ft_strlen(skip);
	while (old && old[i])
	{
		if (ft_strncmp(old[i], skip, len) == 0 && old[i][len] == '=')
			i++;
		else
		{
			new[j] = ft_strdup(old[i]);
			if (!new[j])
				return (M_FAIL);
			j++;
			i++;
		}
	}
	return (SUCCESS);
}

char	**unset_val(char **en, char *arg)
{
	char	**new;

	if (!en || !arg)
		return (NULL);
	if (!find_word(en, arg))
		return (NULL);
	new = ft_calloc(ft_strlen_double(en) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	if (new_arg(new, en, arg) < SUCCESS)
		new = (char **)ft_double_sfree((void **)new);
	return (new);
}

int	ft_unset(char **av, int re_in, int re_out, char **en)
{
	size_t	i;
	char	**tmp;

	i = 1;
	(void)re_in;
	(void)re_out;
	if (!en)
		en = ft_return_ptr(NULL, ENV_C);
	while (av && av[i])
	{
		tmp = unset_val(en, av[i]);
		if (tmp)
		{
			ft_double_sfree((void **)en);
			en = ft_return_ptr(tmp, ENV_C);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
