/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_local.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:24:33 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

short	get_result(int err, char *name, int *f, char *mal)
{
	if (!mal && err == SUCCESS)
	{
		*f = M_FAIL;
		return (err_msg(NO_FREE, FAIL, MS_NAME \
			"Malloc fail : ft_execution_buildin"));
	}
	else if (err == EACCES)
	{
		*f = 126;
		ft_printf(STDERR_FILENO, \
		"%ominishell: %s: Permission denied\n", NULL, name);
		return (FAIL);
	}
	return (SUCCESS);
}

void	free_execution(t_cmd **in, t_mshell *shell)
{
	t_waitp	*pid;
	t_waitp	*next;

	pid = shell->keep_wait;
	while (pid)
	{
		next = pid->next;
		ft_free(pid->name);
		ft_free(pid);
		pid = next;
	}
	shell->keep_wait = NULL;
	cmd_free(in);
	shell->cmd_list = NULL;
	shell->path = (char **)ft_double_sfree((void **)shell->path);
	shell->en = (char **)ft_double_sfree((void **)shell->en);
	shell->en = (char **)ft_double_sfree((void **)shell->aliace);
	shell->s = ft_free(shell->s);
	shell->prompt = ft_free(shell->prompt);
	shell->pwd = ft_free(shell->pwd);
	shell->rest = ft_free(shell->rest);
}
