#include "ms.h"

static int	test_arg(char *av)
{
	size_t	i;
	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]) || i > 11)
		{
		ft_printf(2, \
		"%o"MS_NAME"\b: ms -j: invalid args , take a number from 0 to 100\n", \
		NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

static	int find_next_line(t_mshell *shell, long long tofind)
{
	t_index					list;
	long long				j;

	j = 0;
	ft_bzero(&list, sizeof(list));
	ft_set_mode(-1);
	while (shell->s && shell->s[list.i])
	{
		printf("%ld\n", list.i);
		while (shell->s[list.i] && ft_set_mode(0) != 0)
			ft_set_mode(shell->s[list.i++]);
		if (j == tofind)
		{
			printf("%s\n", shell->s + list.i + 1);
			(*shell->s_line) = list.i;
			return (0);
		}
		if (shell->s[list.i] && shell->s[list.i] == ';')
			j++;
		list.i++;
		printf("ici\n");
	}
	return (1);
}

int	ms_jump(char *line, size_t *j)
{
	t_mshell	*shell;
	long long	tofind;

	(*j) += 1;
	return (1);
	shell = ft_return_ptr(NULL, SYS);
	if (!shell)
		return (1);
	if (!line || !line[0])
	{
		ft_printf(2, "%o"MS_NAME"\b: ms -j: empty line\n", NULL);
		return (1);
	}
	if (test_arg(line))
		return (1);
	tofind = atoll(line); // !use my code here
	(*shell->s_line) = 0;
	if (tofind != 0)
		return (find_next_line(shell, tofind));
	return (0);
}
