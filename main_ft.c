/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:32:01 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/20 17:32:17 by anboisve         ###   ########.fr       */
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

static	void	get_user(t_mshell *shell)
{
	char	*logname;
	char	*new;

	logname = NULL;
	new = NULL;
	find_git(shell);
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
		ft_printf(NO_PRINT, "%o%s%s"WHT"%s(%S)[%s%s"WHT"]"PROMPT, \
		&shell->prompt, shell->sys_color.c1, shell->pwd, new, err_code(shell), \
		shell->sys_color.c3, logname);
	else
		ft_printf(NO_PRINT, "%o%s%s"WHT"%s(%S)"PROMPT, \
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

static int	set_cmd_input(t_mshell *shell)
{
	if (!shell->av)
	{
		shell->s = NULL;
		return (0);
	}
	if (shell->s_in)
		shell->s = shell->s_in;
	else if (ft_strlen_double(shell->av) > 1 && !is_number_list(shell->av[1]))
	{
		if (ft_strncmp(shell->av[1], "-c", 3) == 0)
			shell->s = ft_strdup(shell->av[2]);
		else
		{
			ft_printf(2, "%o"MS_NAME"\b: %s unknow flag\n", NULL, shell->av[1]);
			shell->pec = 1;
		}
		shell->s_in = NULL;
		shell->av = NULL;
	}
	else
		shell->s = readline(shell->prompt);
	return (0);
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
	return (ft_caller(shell));
}
