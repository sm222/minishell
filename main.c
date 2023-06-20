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
	shell->cmd_list = NULL;
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
	int		loop_test;

	(void)ac;
	(void)av;
	loop_test = 1;
	start_shell(&shell, en);
	while (loop_test--)
	{
		debug(SUCCESS, "-	-	-	-", FILE_DEF);
		//shell.s = readline(PROMPT);
		shell.s = ft_strdup("cat Makefile");
		shell.cmd_list = NULL;
		if (shell.s && *shell.s)
		{
			debug(SUCCESS, shell.s, FILE_DEF);
			cmd_make_node_last(&shell.cmd_list, ft_split("ls", ' '), make_token(0, 0, 0));
			cmd_make_node_last(&shell.cmd_list, ft_split("cat -e", ' '), make_token(0, 0, 0));
			run_cmd(shell.cmd_list);
			add_history(shell.s);
		}
		ft_free(shell.s);
	}
	rl_clear_history();
	free_shell(&shell);
	return (0);
}
