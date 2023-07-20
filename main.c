#include "include/minishell.h"
#include <fcntl.h>


static void	free_shell(t_mshell *shell)
{
	if (!shell)
		return ;
	ft_putstr_fd("test end\n", 2);
	ft_free(shell->info);
	ft_free(shell->s);
	ft_free(shell->tmp);
	ft_double_sfree((void **)shell->path);
	ft_double_sfree((void **)shell->en);
}

static int	start_shell(t_mshell *shell, char **en)
{
	if (!shell || !en)
		return (BAD_ARGS);
	shell->cmd_list = NULL;
	shell->en = ft_cpy_double_char(en);
	if (get_env_path(shell) <= FAIL)
		return (127);
	ft_return_ptr(shell, SYS);
	ft_return_ptr(shell->path, PATH);
	ft_return_ptr(&shell->pec, PEC);
	ft_return_ptr(shell->en, ENV_C);
	return (SUCCESS);
}

int	main(int ac, char **av, char **en)
{
	t_mshell	shell;
	int		loop_test;
	int	flag = 0;

	(void)ac;
	(void)av;
	ft_bzero(&shell, sizeof(t_mshell));
	loop_test = 100;
	if (start_shell(&shell, en) != SUCCESS)
		return (FAIL);
	print_logo();
	ft_b_set_flag(&flag, BUILT_IN, TRUE);
	while (loop_test--)
	{
		shell.info = getcwd(NULL, 0);
		ft_printf(-1, "%o"GRN"%s "WHT"$ ", &shell.tmp, shell.info);
		shell.s = readline(shell.tmp);
		shell.cmd_list = NULL;
		if (!shell.s)
			break ;
		if (shell.s && *shell.s)
		{
			cmd_make_node_last(&shell.cmd_list, ft_split(shell.s, ' '), make_token(flag, 0, 0));
			run_cmd(shell.cmd_list);
			add_history(shell.s);
		}
		shell.s = ft_free(shell.s);
		shell.info = ft_free(shell.info);
		shell.tmp = ft_free(shell.tmp);
	}
	rl_clear_history();
	free_shell(&shell);
	return (0);
}
