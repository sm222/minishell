
#include "export.h"

int	print_env(char **en, int re_out)
{
	size_t	i;

	i = 0;
	while (en && en[i])
		ft_printf(re_out, "%odeclare -x %s\n", NULL ,en[i++]);
	return (EXIT_SUCCESS);
}

short	look_for_dup(char **env, char *name)
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

short	export_new(char **en)
{
	
}


int	ft_export(char **av, int re_in, int re_out, char **en)
{
	size_t	i;

	i = 1;
	(void)re_in;
	if (!en)
		en = ft_return_ptr(NULL, ENV_C);
	if (!en)
		return (2);
	if (ft_strlen_double(av) == 1)
		return (print_env(en, re_out));
	while (av[i])
	{

	}
	return (EXIT_SUCCESS);
}