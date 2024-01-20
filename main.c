/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:31:47 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/19 23:40:30 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include "include/readline/readline.h"
#include <term.h>

static void	free_shell(t_mshell *shell, int ac)
{
	if (!shell)
		return ;
	if (ac < 2)
		ft_putstr_fd(BLU"GoodBye~!"WHT"\n", 2);
	rl_clear_history();
	ft_free(shell->pwd);
	ft_free(shell->s);
	ft_free(shell->prompt);
	ft_double_sfree((void **)shell->path);
	ft_double_sfree((void **)shell->en);
	ft_double_sfree((void **)shell->alias);
	ft_free(shell->termios);
}

static void	do_logo(char **av)
{
	if (ft_strlen_double(av) > 2)
		return ;
	if (av[1] && av[1][0] != 0 && ft_strlen(av[1]) > 8)
		print_logo(av[1]);
	else
		print_logo(NULL);
	ft_printf(1, "%o%S"V_MINI"\n"WHT, NULL, ft_make_color(20, 84, 255));
}

static void	set_ptr_all(t_mshell *shell)
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
	shell->sys_color.pik = PIK;
	shell->sys_color.wht = WHT;
	shell->sys_color.tox = TOX;
	shell->sys_color.git = GIT;
	shell->sys_color.org = ORG;
	shell->sys_color.git_b = GIT_B;
	shell->sys_color.c1 = GRN;
	shell->sys_color.c2 = GIT;
	shell->sys_color.c3 = TOX;
	shell->sys_color.c4 = GIT_B;
	shell->sys_color.c5 = RED;
}

static int	set_shlvl(t_mshell *data)
{
	char	*s;
	int		lv;
	char	*tmp;

	s = get_env(data->en, "SHLVL");
	lv = ft_atoi(s);
	lv++;
	ft_printf(NO_PRINT, "%oex\bSHLVL=%d", &tmp, lv);
	export_in_main(data, tmp);
	ft_free(tmp);
	return (SUCCESS);
}

static int	start_shell(t_mshell *shell, char **en, char **av)
{
	char	*new;
	char	**spl;

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
	shell->compile_dir = CONPILE_DIR;
	export_main(shell);
	set_shlvl(shell);
	shell->termios = ft_calloc(1, sizeof(struct termios));
	tcgetattr(0, shell->termios);
	return (SUCCESS);
}


int	main(int ac, char **av, char **en)
{
	t_mshell	shell;
	char		*new;
	char		**spl;

	if (NORUN)
		return(ft_putstr_fd("sorry code don't work on this system", 2), 1);
	ft_signal_handler(CMD);
	if (start_shell(&shell, en, av) != SUCCESS)
		return (FAIL);
	shell.av = av;
	set_alias(&shell, ac);
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
	free_shell(&shell, ac);
	return (shell.pec);
}

//https://opensource.apple.com/source/gdb/gdb-962/src/readline/

/*

readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs

*/