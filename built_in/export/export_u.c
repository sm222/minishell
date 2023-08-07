#include "export.h"

static short	look_new_arg(char *old, char *new)
{
	if (ft_strchr(old, '=') && !ft_strchr(new, '='))
		return (0);
	return (1);
}

char	**change_arg_env(char **en, int i, char *new)
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

static void	print_type(const char *s, int re_out)
{
	size_t	i;
	char	*name;

	i = 0;
	name = ft_calloc(ft_strlen(s) + 1 , sizeof(char));
	if (s && name)
	{
		while (s[i] && s[i] != '=')
		{
			name[i] = s[i];
			i++;
		}
		if (s[i] == '=')
			ft_printf(re_out, "%odeclare -x %s=\"%s\"\n", \
			NULL, name, s + i + 1);
		else
			ft_printf(re_out, "%odeclare -x %s\n", NULL, name);
		ft_free(name);
	}
}

int	print_env(char **en, int re_out)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (en && en[i] && en[i + 1])
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
		print_type(en[i++], re_out);
	return (EXIT_SUCCESS);
}
