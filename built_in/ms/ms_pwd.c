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
		return (shell->sys_color.org);
	if (i == 2)
		return (shell->sys_color.yel);
	if (i == 3)
		return (shell->sys_color.git);
	if (i == 4)
		return (shell->sys_color.grn);
	if (i == 5)
		return (shell->sys_color.blu);
	if (i == 6)
		return (shell->sys_color.tox);
	if (i == 7)
		return (shell->sys_color.pik);
	if (i == 8)
		return (shell->sys_color.mag);
	if (i == 9)
		return (shell->sys_color.git_b);
	return (NULL);
}

static int	ms_color(char **av, t_mshell *shell)
{
	char	*new_c;

	if (!av[0][2] || !av[0][3] || av[0][4] || \
		!ft_isdigit(av[0][2]) || (!ft_isdigit(av[0][3]) && av[0][3] != '-'))
	{
		ft_printf(2, "%o"MS_NAME"\b: -s C= need 2 numbers or 1 number and - \
to set it to white\n", NULL);
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

static int	color_number(char const *s)
{
	if (ft_strcmp(s, RED) == 0)
		return ('0');
	if (ft_strcmp(s, ORG) == 0)
		return ('1');
	if (ft_strcmp(s, YEL) == 0)
		return ('2');
	if (ft_strcmp(s, GIT) == 0)
		return ('3');
	if (ft_strcmp(s, GRN) == 0)
		return ('4');
	if (ft_strcmp(s, BLU) == 0)
		return ('5');
	if (ft_strcmp(s, CYN) == 0)
		return ('6');
	if (ft_strcmp(s, PIK) == 0)
		return ('7');
	if (ft_strcmp(s, MAG) == 0)
		return ('8');
	if (ft_strcmp(s, GIT_B) == 0)
		return ('9');
	return ('-');
}

static void	number_color(t_col_sys const data)
{
	ft_printf(2, "%oyour color rn\n", NULL);
	ft_printf(2, "%oPATH %c, ", NULL, color_number(data.c1));
	ft_printf(2, "%oGIT BRANCH %c, ", NULL, color_number(data.c2));
	ft_printf(2, "%oUSER %c, ", NULL, color_number(data.c3));
	ft_printf(2, "%oGIT BRANCH LOGO %c, ", NULL, color_number(data.c4));
	ft_printf(2, "%oERROR COLOR %c.\n", NULL, color_number(data.c5));
}

static void	show_color(void)
{
	t_mshell	*shell;
	int			i;

	i = 0;
	shell = ft_return_ptr(NULL, SYS);
	if (!shell)
		return ;
	ft_printf(2, "%ocolor ~>\n", NULL);
	ft_printf(2, "%o"LINE"\n", NULL);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.red, i++);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.org, i++);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.yel, i++);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.git, i++);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.grn, i++);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.blu, i++);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.tox, i++);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.pik, i++);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.mag, i++);
	ft_printf(2, "%o%s"TXT_C"%d|"WHT"\n", NULL, shell->sys_color.git_b, i++);
	ft_printf(2, "%o%s"TXT_C"-|"WHT"\n", NULL, shell->sys_color.wht);
	ft_printf(2, "%o"LINE"\n", NULL);
	ft_printf(2, "%o"EXP"\n", NULL);
	ft_printf(2, "%oex: ms -s C=25\n", NULL);
	number_color(shell->sys_color);
	ft_printf(2, "%o------------------------------------\n<~\n", NULL);
}

int	ms_edit(char **av, size_t *j)
{
	t_mshell	*shell;

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
	else if (ft_strncmp(av[0], "C", 2) == 0)
		return (show_color(), 0);
	else
		ft_printf(2, "%o"MS_NAME"\b: ms: -s unknow %s\n", NULL, av[0]);
	return (1);
}
