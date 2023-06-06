#include "minishell.h"

static void	free_shell(t_mshell *shell)
{
	if (!shell)
		return ;
	ft_double_sfree((void **)shell->path);
	ft_double_sfree((void **)shell->en);
}

static int	start_shell(t_mshell *shell, char **en)
{
	if (!shell)
		return (BAD_ARGS);
	shell->en = ft_cpy_double_char(en);
	if (!shell->en)
		return (M_FAIL);
	if (get_env_path(shell) <= FAIL)
		return (127);
	fr_return_ptr(shell->path, PATH);
	fr_return_ptr(shell, SYS);
	return (SUCCESS);
}

int	main(int ac, char **av, char **en)
{
	char		*s;
	t_mshell	shell;
	t_cmd		*in;
	int		loop_test;

	(void) ac;
	(void)av;
	loop_test = 10;
	start_shell(&shell, en);
	while (loop_test)
	{
		s = readline(PROMPT);
		in = NULL;
		if (s && *s)
		{
			cmd_make_node_last(&in, ft_split("ls", ' '), make_token(-1, -1 ,0));
			cmd_make_node_last(&in, ft_split("cat", ' '), make_token(-1, -1 ,0));
			run_cmd(in);
			add_history(s);
		}
		ft_free(s);
		printf("%d\n", loop_test);
		loop_test--;
	}
	rl_clear_history();
	free_shell(&shell);
	return (0);
}
