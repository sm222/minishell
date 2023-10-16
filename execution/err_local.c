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

void	free_execution(t_cmd *in, t_mshell *shell)
{
	cmd_free(&in);
	ft_double_sfree((void **)shell->path);
	ft_double_sfree((void **)shell->en);
	ft_free(shell->s);
	ft_free(shell->prompt);
	ft_free(shell->pwd);
	ft_free(shell->rest);
}
