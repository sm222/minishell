#include "edit.h"

static int shell_edit(char **av, size_t *j)
{
	int	tab;
	t_mshell *shell;

	shell = ft_return_ptr(NULL, SYS);
	if (!av[0])
	{
		ft_printf(2, "%o"MS_NAME"\b: -s need args\n", NULL);
		return (1);
	}
	*j += 1;
	if (ft_strncmp(av[0], "DIRL=", 5) == 0)
	{
		if (!av[0][5])
		{
			ft_printf(2, "%o"MS_NAME"\b: -s DIRL need a number\n", NULL);
		}
		tab = ft_atoi(av[0] + 5);
		if (shell)
			shell->dir_len = (size_t)tab;
		return (0);
	}
	else
		ft_printf(2, "%o"MS_NAME"\b: -s unknow %s\n", NULL, av[0]);
	return (1);
}

int	ft_edit(char **av, int re_in, int re_out, char **en)
{
	size_t	i;
	size_t	j;
	int	err;

	(void)re_in;
	(void)re_out;
	(void)en;
	err = 0;
	i = ft_strlen_double(av);
	j = 1;
	while (j < i)
	{
		if (ft_strncmp(av[j], "-s", 3) == 0)
			err += shell_edit(av + j + 1, &j);
		else
		{
			ft_printf(2, "%o"MS_NAME"\b: %s not valid\n", NULL, av[j]);
			err = 1;
		}
		j++;
	}
	return (err);
}
