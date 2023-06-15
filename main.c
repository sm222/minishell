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
	t_mshell	shell;
	t_cmd		*in;
	int		loop_test;

	(void)ac;
	(void)av;
	loop_test = 1;
	start_shell(&shell, en);
	while (loop_test)
	{
		debug(SUCCESS, "-	-	-	-", FILE_DEF);
		shell.s = readline(PROMPT);
		in = NULL;
		if (shell.s && *shell.s)
		{
			debug(SUCCESS, shell.s, FILE_DEF);
			cmd_make_node_last(&in, ft_split(shell.s, ' '), make_token(-1, -1 ,0,  PIPE_OUT));
			cmd_make_node_last(&in, ft_split("cat -e", ' '), make_token(-1, -1 ,0, PIPE_IN_OUT));
			cmd_make_node_last(&in, ft_split("ls", ' '), make_token(-1, -1 ,0, PIPE_IN_OUT));
			cmd_make_node_last(&in, ft_split("a -e", ' '), make_token(-1, -1 ,0, PIPE_IN_OUT));
			cmd_make_node_last(&in, ft_split("cat -e", ' '), make_token(-1, -1 ,0, PIPE_IN));
			run_cmd(in);
			add_history(shell.s);
		}
		ft_free(shell.s);
		loop_test--;
	}
	rl_clear_history();
	free_shell(&shell);
	return (0);
}
