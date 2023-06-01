#include "minishell.h"

int	main(int ac, char **av, char **en)
{
	char		*s;
	char		*out;
	t_mshell	shell;

	(void)ac;
	(void)av;
	shell.en = ft_cpy_double_char(en);
	ft_printf(1, "%d\n", get_env_path(&shell));
	s = PROMPT;
	while (s)
	{
		s = readline(PROMPT);
		if (s && *s)
		{
			ft_printf(1, "%d\n", find_path(s, &out, shell.path));
			printf("out %s\n", out);
			add_history(s);
		}
		ft_free(s);
	}
	ft_double_sfree((void **)shell.en);
	rl_clear_history();
	return (0);
}
