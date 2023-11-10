#include "ms.h"

static int	ms_pwd(char **av, t_mshell *shell)
{
	int	tab;

	if (!av[0][5])
	{
		ft_printf(2, "%o"MS_NAME"\b: ms -s DIRL need a number\n", NULL);
		return (1);
	}
	tab = ft_atoi(av[0] + 5);
	if (shell)
		shell->dir_len = (size_t)tab;
	return (0);
}

static char	*color_chose(int i, t_mshell *shell)
{
	if (i == 0)
		return (shell->sys_color.red);
	if (i == 1)
		return (shell->sys_color.grn);
	if (i == 2)
		return (shell->sys_color.yel);
	if (i == 3)
		return (shell->sys_color.blu);
	if (i == 4)
		return (shell->sys_color.mag);
	if (i == 5)
		return (shell->sys_color.cyn);
	if (i == 6)
		return (shell->sys_color.wht);
	if (i == 7)
		return (shell->sys_color.tox);
	if (i == 8)
		return (shell->sys_color.git);
	return (NULL);
}

static int	ms_color(char **av, t_mshell *shell)
{
	char	*new_c;

	if (!av[0][2] || !av[0][3] || av[0][4] || \
		!ft_isdigit(av[0][2]) || !ft_isdigit(av[0][3]))
	{
		ft_printf(2, "%o"MS_NAME"\b: -s C= need 2 numbers\n", NULL);
		return (1);
	}
	if (shell)
	{
		new_c = color_chose(av[0][3] - '0', shell);
		if (av[0][2] - '0' == 0)
			shell->sys_color.c1 = new_c;
		if (av[0][2] - '0' == 1)
			shell->sys_color.c2 = new_c;
		if (av[0][2] - '0' == 2)
			shell->sys_color.c3 = new_c;
		if (av[0][2] - '0' == 3)
			shell->sys_color.c4 = new_c;
		if (av[0][2] - '0' == 4)
			shell->sys_color.c5 = new_c;
	}
	return (0);
}

int ms_edit(char **av, size_t *j)
{
	t_mshell *shell;

	shell = ft_return_ptr(NULL, SYS);
	if (!av[0])
	{
		ft_printf(2, "%o"MS_NAME"\b: ms: -s need args\n", NULL);
		return (1);
	}
	*j += 1;
	if (ft_strncmp(av[0], "DIRL=", 5) == 0)
		return (ms_pwd(av, shell));
	else if (ft_strncmp(av[0], "C=", 2) == 0)
		return (ms_color(av, shell));
	else
		ft_printf(2, "%o"MS_NAME"\b: ms: -s unknow %s\n", NULL, av[0]);
	return (1);
}