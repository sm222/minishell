
#include "export.h"

int	print_env(char **en, int re_out)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (en && en[i + 1])
	{
		if (ft_strcmp(en[i], en[i + 1]) > 0)
		{
			tmp = en[i + 1];
			en[i + 1] = en[i];
			en[i] = tmp;
			i = -1;
		}
		i++;
	}
	i = 0;
	while (en && en[i])
		ft_printf(re_out, "%odeclare -x %s\n", NULL ,en[i++]);
	ft_double_sfree((void **)en);
	return (EXIT_SUCCESS);
}

int	look_for_dup(char **env, char *name)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (env && env[i])
	{
		len = 0;
		while (env[i][len] && env[i][len] != '=')
			len++;
		if (ft_strncmp(env[i], name, len + 1) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**export_new(char **en, char *arg)
{
	char	**new;
	int		i;

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
		while (--i)
			new[i] = en[i];
	}
	return (new);
}


int	ft_export(char **av, int re_in, int re_out, char **en)
{
	size_t	i;
	char	**tmp;

	(void)re_in;
	if (ft_strlen_double(av) == 1)
		return (print_env(ft_cpy_double_char(en), re_out));
	i = 1;
	while (av && av[i])
	{
		tmp = export_new(en, av[i]);
		if (tmp)
		{
			ft_double_sfree((void **)en);
			en = ft_return_ptr(tmp, ENV_C);
			tmp = NULL;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}