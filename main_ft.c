/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:32:01 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/06 16:51:17 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include "lib/lib_ft/ft_printf.h"

static char	*get_path(char *new, char *old)
{
	if (!new && old)
		return (old);
	else if (new && old)
	{
		ft_free(old);
		return (new);
	}
	else if (!new && !old)
		return (ft_strdup("?"));
	else if (new && !old)
		return (new);
	return (NULL);
}

static char	*err_code(t_mshell *shell)
{
	char	*new;

	new = NULL;
	if (shell->pec != 0)
		ft_printf(NO_PRINT, "%o"RED"%d"WHT, &new, shell->pec);
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
	logname = get_env(shell->en, "LOGNAME");
	shell->pwd = get_path(getcwd(NULL, 0), shell->pwd);
	if (shell->git_status)
	{
		ft_printf(NO_PRINT, "%o🌲"GIT"%S"WHT, &new, shell->git_status);
		shell->git_status = NULL;
	}
	if (logname)
		ft_printf(NO_PRINT, "%o"GRN"%s"WHT"%s(%S)["TOX"%s"WHT"]$ ", \
		&shell->prompt, shell->pwd, new, err_code(shell), logname);
	else
		ft_printf(NO_PRINT, "%o"GRN"%s"WHT"%s(%S)$ ", \
		&shell->prompt, shell->pwd, new, err_code(shell));
	ft_free(new);
}

static short	ft_caller(t_mshell *shell)
{
	size_t	i;
	size_t	j;
	short	type;

	j = 0;
	type = 0;
	shell->re_draw = 1;
	while (j < ft_strlen(shell->s))
	{
		i = look_for_type(shell->s + j, &type);
		if (type == -1)
			return (FAIL);
		shell->rest = ft_strndup(shell->s + j, i);
		if (!shell->rest)
			break ;
		j += i + 2;
		converter(shell->rest, &shell->cmd_list);
		run_cmd(shell->cmd_list, shell);
		free_here_doc(UNLINK);
		shell->rest = ft_free(shell->rest);
		if ((shell->pec != 0 && type == '&') || \
			(shell->pec == 0 && type == '|'))
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
	find_git(shell);
	get_user(shell);
	shell->s = readline(shell->prompt);
	if (!shell->s)
		return (FAIL - 1);
	else if (shell->s[0])
		add_history(shell->s);
	ft_change_dolar(&shell->s, shell->en, 0, shell->pec);
	while (shell->s && shell->s[i] && (shell->s[i] == ' ' || \
	shell->s[i] == '\t'))
		i++;
	if (i == ft_strlen(shell->s))
		return (FAIL);
	ft_set_mode(-1);
	return (ft_caller(shell));
}
