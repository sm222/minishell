#include "minishell.h"

int	main(int ac, char **av, char **en)
{
	char		*s;
	t_cmd		*list;
	t_mshell	shell;

	(void)ac;
	(void)av;
	shell.en = ft_cpy_double_char(en);
	s = PROMPT;
	while (s)
	{
		s = readline(PROMPT);
		if (s && *s)
		{
			add_history(s);
			printf("%d\n", cmd_make_node_last(&list, ft_split(s, ' '), 0));
		}
		ft_free(s);
	}
	cmd_free(list);
	ft_double_sfree((void **)shell.en);
	rl_clear_history();
	return (0);
}
