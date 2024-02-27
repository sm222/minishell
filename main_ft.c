/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:32:01 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/27 10:35:11 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

/// @brief use to short the path in the prompt
/// example : home/antoine/Documents/42/minishell
/// to        42/minishell
/// @param path the path use
/// @param len number of word want too keep, like ex woud be 2
/// if len 0 return all path
/// @return new path
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
		if (path[i] == PATH_SEP)
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
	char	*buffl;
	char	*buffr;

	new = NULL;
	buffl = NULL;
	buffr = NULL;
	if (shell->pec < 100)
		buffl = " ";
	if (shell->pec  < 10)
		buffr = " ";
	if (shell->pec == 42)
		ft_printf(NO_PRINT, "%o"BLU"%s%d%s"WHT, &new, buffl, shell->pec, buffr);
	else if (shell->pec != 0)
		ft_printf(NO_PRINT, "%o%s%s%d%s"WHT, &new, shell->sys_color.c5, buffl ,shell->pec, buffr);
	else
		ft_printf(NO_PRINT, "%o%s%d%s", &new, buffl, shell->pec, buffr);
	return (new);
}

static void set_shell_lv(t_mshell *shell, char *str)
{
	short	i;
	char	*shlv;

	i = 0;
	ft_bzero(str, SH_LV_MAX + 1);
	shlv = get_env(shell->en, "SHLVL");
	if (shlv && ft_atoi(shlv) > 2)
	{
		while (shlv[i] && i < SH_LV_MAX)
		{
			str[i] = shlv[i];
			i++;
		}
	}
}

void	get_user(t_mshell *shell)
{
	char	*logname;
	char	*new;
	char	shlv[SH_LV_MAX + 1];

	logname = NULL;
	new = NULL;
	find_git(shell);
	set_shell_lv(shell, shlv);
	logname = get_env(shell->en, "LOGNAME");
	shell->pwd = get_path(getcwd(NULL, 0), shell->pwd, shell);
	// ||          pwd here          ||
	if (shell->git_status)
	{
		ft_printf(NO_PRINT, "%o%sY"WHT"%s%S"WHT, \
		&new, shell->sys_color.c4, shell->sys_color.c2, shell->git_status);
		shell->git_status = NULL;
	}
	if (logname)
		ft_printf(NO_PRINT, "%o%s%s"WHT"%s(%S)[%s%s"WHT"]%s"PROMPT, \
		&shell->prompt, shell->sys_color.c1, shell->pwd, new, err_code(shell), \
		shell->sys_color.c3, logname, shlv);
	else
		ft_printf(NO_PRINT, "%o%s%s"WHT"%s(%S)%s"PROMPT, \
		&shell->prompt, shell->sys_color.c1, shell->pwd, new, err_code(shell), shlv);
	ft_free(new);
}

//\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$

static short	lunch(t_mshell *shell)
{
	if (converter(shell->rest, &shell->cmd_list) == SUCCESS)
	{
		run_cmd(shell->cmd_list, shell);
	}
	else
	{
		shell->pec = 258;
		cmd_free(&shell->cmd_list);
	}
	free_here_doc(UNLINK);
	return (SUCCESS);
}

/// @brief
/// @param shell
/// @param l
/// @return 1 to break 0 to continue
static int	skip_to_next(t_mshell *shell, t_index *l)
{
	ft_set_mode(-1);
	l->k = ft_strlen(shell->s);
	if ((shell->pec != 0 && l->type == '&') || (shell->pec == 0 && l->type == '|'))
	{
		while (l->j < l->k)
		{
			ft_set_mode(shell->s[l->j]);
			if (ft_set_mode(0) < 1 && shell->s[l->j] == ';')
			{
				l->j++;
				return (0);
			}
			else
				l->j++;
		}
		return (1);
	}
	return (0);
}


static short	ft_caller(t_mshell *shell)
{
	t_index	l;

	ft_bzero(&l, sizeof(t_index));
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
		lunch(shell);
		shell->rest = ft_free(shell->rest);
		if (skip_to_next(shell, &l))
			break ;
	}
	return (SUCCESS);
}

static short	is_number_list(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	set_cmd_input(t_mshell *shell)
{
	if (!shell->av)
		return ;
	if (shell->s_in)
		shell->s = shell->s_in;
	else if (ft_strlen_double(shell->av) > 1 && !is_number_list(shell->av[1]))
	{
		if (ft_strncmp(shell->av[1], "-c", 3) == 0)
			shell->s = ft_strdup(shell->av[2]);
		else if (ft_strncmp(shell->av[1], "-r", 3) == 0)
			shell->s = get_next_line(STDIN_FILENO);
		else
		{
			ft_printf(2, "%o"MS_NAME"\b: %s unknow flag\n", NULL, shell->av[1]);
			shell->pec = 1;
		}
		shell->s_in = NULL;
		shell->av = NULL;
	}
	else if (!shell->isatty)
		shell->s = readline(shell->prompt);
	else
	{
		ft_putendl_fd(shell->prompt, STDOUT_FILENO);
		shell->s = get_next_line(STDIN_FILENO);
	}
}

short	reset_data_main(t_mshell *shell)
{
	size_t	i;

	i = 0;
	shell->keep_wait = NULL;
	shell->s = ft_free(shell->s);
	shell->prompt = ft_free(shell->prompt);
	get_user(shell);
	set_cmd_input(shell);
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
	shell->re_draw = 1;
	return (ft_caller(shell));
}
