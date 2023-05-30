#include "minishell.h"

int	main(int ac, char **av, char **en)
{
	char		*s;
	char		*out;
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
			printf("%d\n", find_path("/bin/cat", &out, ))
		}
		ft_free(s);
	}
	ft_double_sfree((void **)shell.en);
	rl_clear_history();
	return (0);
}
