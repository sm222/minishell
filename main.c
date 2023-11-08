/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:31:47 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/07 23:27:46 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

static void	free_shell(t_mshell *shell)
{
	if (!shell)
		return ;
	ft_putstr_fd(BLU"GoodBye~!"WHT"\n", 2);
	rl_clear_history();
	ft_free(shell->pwd);
	ft_free(shell->s);
	ft_free(shell->prompt);
	ft_double_sfree((void **)shell->path);
	ft_double_sfree((void **)shell->en);
	ft_double_sfree((void **)shell->aliace);
}

static void	do_logo(char **av)
{
	if (av[1] && av[1][0] != 0 && ft_strlen(av[1]) > 8)
		print_logo(av[1]);
	else
		print_logo(NULL);
	ft_printf(1, "%o%S"V_MINI"\n"WHT, NULL, ft_make_color(20, 84, 255));
}

static int	set_ptr_all(t_mshell *shell)
{
	ft_return_ptr(shell, SYS);
	ft_return_ptr(shell->path, PATH);
	ft_return_ptr(&shell->pec, PEC);
	ft_return_ptr(shell->en, ENV_C);
	ft_return_ptr(&shell->exit, EX_F);
	ft_return_ptr(&shell->doc, DOC);
	ft_return_ptr(&ft_signal_handler, SIG);
	ft_return_ptr(&clean_shell, CLEAN);
	ft_return_ptr(&free_here_doc, FREE_DOC);
	shell->sys_color.red = RED;
	shell->sys_color.grn = GRN;
	shell->sys_color.yel = YEL;
	shell->sys_color.blu = BLU;
	shell->sys_color.mag = MAG;
	shell->sys_color.cyn = CYN;
	shell->sys_color.wht = WHT;
	shell->sys_color.tox = TOX;
	shell->sys_color.git = GIT;
	shell->sys_color.c1 = GRN;
	shell->sys_color.c2 = GIT;
	shell->sys_color.c3 = TOX;
	return (0);
}

static int	start_shell(t_mshell *shell, char **en, char **av)
{
	char	*new;
	char	**spl;

	if (!shell || !en)
		return (BAD_ARGS);
	ft_bzero(shell, sizeof(t_mshell));
	shell->dir_len = 3;
	shell->en = ft_cpy_double_char(en);
	if (get_env_path(shell) <= FAIL)
		return (1);
	set_ptr_all(shell);
	ft_printf(NO_PRINT, "%oex\bOLDPWD\bPWD\bPATH=%s:"MINI_BIN, \
		&new, get_env(shell->en, "PATH"));
	spl = ft_split(new, '\b');
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
	char		*new;
	char		**spl;

	(void)ac;
	ft_signal_handler(CMD);
	if (start_shell(&shell, en, av) != SUCCESS)
		return (FAIL);
	set_aliace(&shell);
	while (SUCCESS)
	{
		if (reset_data_main(&shell) == FAIL -1)
			break ;
		shell.re_draw = 0;
		ft_printf(NO_PRINT, "%oex\b_=%s", &new, ft_rfind_char(shell.s, '\b'));
		spl = ft_split(new, '\b');
		ft_export(spl, 0, 1, shell.en);
		shell.en = ft_return_ptr(NULL, ENV_C);
		new = ft_free(new);
		spl = (char **)ft_double_sfree((void **)spl);
	}
	free_shell(&shell);
	return (shell.pec);
}

//https://opensource.apple.com/source/gdb/gdb-962/src/readline/