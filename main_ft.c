/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:32:01 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/08 15:08:07 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

static char	*make_new_path_len(char *path, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = ft_strlen(path);
	j = 0;
	if (!path || !len)
		return (path);
	while (i--)
	{
		if (path[i] == '/')
			j++;
		if (j == len)
			break ;
	}
	new = ft_strdup(path + i + 1);
	ft_free(path);
	return (new);
}

static char	*get_path(char *new, char *old, t_mshell *shell)
{
	if (!new && old)
		return (old);
	else if (new && old)
	{
		ft_free(old);
		return (make_new_path_len(new, shell->dir_len));
	}
	else if (!new && !old)
		return (ft_strdup("?"));
	else if (new && !old)
		return (make_new_path_len(new, shell->dir_len));
	return (NULL);
}

static char	*err_code(t_mshell *shell)
{
	char	*new;

	new = NULL;
	if (shell->pec == 42)
		ft_printf(NO_PRINT, "%o"BLU"%d"WHT, &new, shell->pec);
	else if (shell->pec != 0)
		ft_printf(NO_PRINT, "%o%s%d"WHT, &new, shell->sys_color.c5 ,shell->pec);
	else
		ft_printf(NO_PRINT, "%o%d", &new, shell->pec);
	return (new);
}

static	void	get_user(t_mshell *shell)
{
	char	*logname;
	char	*new;

	logname = NULL;
	new = NULL;
	find_git(shell);
	logname = get_env(shell->en, "LOGNAME");
	shell->pwd = get_path(getcwd(NULL, 0), shell->pwd, shell);
	if (shell->git_status)
	{
		ft_printf(NO_PRINT, "%o%sY"WHT"%s%S"WHT, \
		&new, shell->sys_color.c4, shell->sys_color.c2, shell->git_status);
		shell->git_status = NULL;
	}
	if (logname)
		ft_printf(NO_PRINT, "%o%s%s"WHT"%s(%S)[%s%s"WHT"]$ ", \
		&shell->prompt, shell->sys_color.c1, shell->pwd, new, err_code(shell), \
		shell->sys_color.c3, logname);
	else
		ft_printf(NO_PRINT, "%o%s%s"WHT"%s(%S)$ ", \
		&shell->prompt, shell->sys_color.c1, shell->pwd, new, err_code(shell));
	ft_free(new);
}
//\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$

static short	ft_caller(t_mshell *shell)
{
	t_index	l;

	ft_bzero(&l, sizeof(t_index));
	shell->re_draw = 1;
	while (l.j < ft_strlen(shell->s))
	{
		l.i = look_for_type(shell->s + l.j, &l.type);
		if (l.type == -1)
			return (FAIL);
		shell->rest = ft_strndup(shell->s + l.j, l.i);
		if (!shell->rest)
			break ;
		if (l.type != '&' && l.type != '|')
			l.j += l.i + 1;
		else
			l.j += l.i + 2;
		converter(shell->rest, &shell->cmd_list);
		run_cmd(shell->cmd_list, shell);
		free_here_doc(UNLINK);
		shell->rest = ft_free(shell->rest);
		if ((shell->pec != 0 && l.type == '&') || \
			(shell->pec == 0 && l.type == '|'))
			break ;
	}
	return (SUCCESS);
}

short	reset_data_main(t_mshell *shell)
{
	size_t	i;

	i = 0;
	shell->keep_wait = NULL;
	shell->s = ft_free(shell->s);
	shell->prompt = ft_free(shell->prompt);
	get_user(shell);
	if (!shell->s_in)
		shell->s = readline(shell->prompt);
	else
		shell->s = shell->s_in;
	if (!shell->s)
		return (FAIL - 1);
	else if (shell->s[0] && !shell->s_in)
		add_history(shell->s);
	shell->s_in = NULL;
	ft_change_dolar(&shell->s, shell->en, false, shell->pec);
	put_alias(&shell->s, shell->alias);
	while (shell->s && shell->s[i] && (shell->s[i] == ' ' || \
	shell->s[i] == '\t'))
		i++;
	if (i == ft_strlen(shell->s))
		return (FAIL);
	ft_set_mode(-1);
	return (ft_caller(shell));
}
