#include "minishell.h"

void	free_shell(t_mshell *shell)
{
	if (!shell)
		return ;
	ft_double_sfree((void **)shell->path);
	ft_double_sfree((void **)shell->en);
}

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
			cmd_make_node_last(&in, ft_split(s, ' '), make_token(-1, -1 ,0));
			cmd_make_node_last(&in, ft_split("cat", ' '), make_token(-1, -1 ,0));
			run_cmd(in);
			add_history(s);
		}
		ft_free(s);
	}
	rl_clear_history();
	free_shell(&shell);
	return (0);
}
