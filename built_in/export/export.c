
#include "export.h"

int	print_env(char **en, int re_out)
{
	size_t	i;

	i = 0;
	while (en && en[i])
		ft_printf(re_out, "%odeclare -x %s\n", NULL ,en[i++]);
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
	char	*new_str;
	int		i;

	if (!en || !arg)
		return (NULL);
	new = NULL;
	i = look_for_dup(en, arg);
	if (i > -1)
	{
		if (ft_printf(NO_PRINT, "%o%s", &new_str, en[i]) == -1)
			return (NULL);
		ft_free(en[i]);
		en[i] = new_str;
	}
	return (new);
}


int	ft_export(char **av, int re_in, int re_out, char **en)
{
	size_t	i;
	char	**tmp;

	i = 1;
	(void)re_in;
	if (ft_strlen_double(av) == 1)
		return (print_env(en, re_out));
	while (av && av[i])
	{
		tmp = export_new(en, av[i]);
		if (tmp)
		{
			ft_double_sfree((void **)en);
			en = ft_return_ptr(tmp, ENV_C);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}