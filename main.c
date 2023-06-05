#include "minishell.h"

int	main(int ac, char **av, char **en)
{
	char		*s;
	t_mshell	shell;
	t_cmd		*in;

	(void) ac;
	(void)av;
	shell.en = ft_cpy_double_char(en);
	if (get_env_path(&shell) <= FAIL)
		return (127);
	fr_return_ptr(shell.path, PATH);
	s = PROMPT;
	while (s)
	{
		s = readline(PROMPT);
		in = NULL;
		if (s && *s)
		{
			cmd_make_node_last(&in, ft_split(s, ' '), 0);
			cmd_make_node_last(&in, ft_split("cat -e", ' '), PIPE);
			//cmd_make_node_last(&in, ft_split("wc", ' '), 0);
			run_cmd(&in);
			cmd_free(in);
			add_history(s);
		}
		ft_free(s);
	}
	ft_double_sfree((void **)shell.en);
	rl_clear_history();
	return (0);
}
