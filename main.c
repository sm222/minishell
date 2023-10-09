#include "include/minishell.h"

static void	free_shell(t_mshell *shell)
{
	if (!shell)
		return ;
	ft_putstr_fd("test end\n", 2);
	ft_free(shell->pwd);
	ft_free(shell->s);
	ft_free(shell->prompt);
	ft_double_sfree((void **)shell->path);
	ft_double_sfree((void **)shell->en);
}

static void	do_logo(char **av)
{
	if (av[1] && av[1][0] != 0 && ft_strlen(av[1]) > 8)
		print_logo(av[1]);
	else
		print_logo(NULL);
	ft_printf(1, "%o%Sv1.0\n"WHT , NULL, ft_make_color(20,84,255));
}

static int	start_shell(t_mshell *shell, char **en, char **av)
{
	char	*new;
	char	**spl;

	if (!shell || !en)
		return (BAD_ARGS);
	ft_bzero(shell, sizeof(t_mshell));
	shell->en = ft_cpy_double_char(en);
	if (get_env_path(shell) <= FAIL)
		return (127);
	ft_return_ptr(shell, SYS);
	ft_return_ptr(shell->path, PATH);
	ft_return_ptr(&shell->pec, PEC);
	ft_return_ptr(shell->en, ENV_C);
	ft_return_ptr(&shell->exit, EX_F);
	ft_return_ptr(&shell->doc, DOC);
	ft_printf(NO_PRINT, "%oex OLDPWD PWD", &new);
	spl = ft_split(new, ' ');
	ft_export(spl, 0, 1, shell->en);
	ft_double_sfree((void **)spl);
	ft_free(new);
	shell->en = ft_return_ptr(NULL, ENV_C);
	do_logo(av);
	return (SUCCESS);
}

int	main(int ac, char **av, char **en)
{
	t_mshell	shell;
	int			loop_test;

	(void)ac;
	loop_test = 100;
	if (start_shell(&shell, en, av) != SUCCESS)
		return (FAIL);
	while (loop_test--)
	{
		if (reset_data_main(&shell) == FAIL -1)
			break ;
		printf("last pec == %d\n", shell.pec);
	}
	rl_clear_history();
	free_shell(&shell);
	return (shell.pec);
}
