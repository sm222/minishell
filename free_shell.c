/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:32:13 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/05 17:56:54 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

static short	free_data_shell(t_mshell *shell)
{
	free_here_doc(NO_UNLINK);
	shell->pwd = ft_free(shell->pwd);
	shell->rest = ft_free(shell->rest);
	shell->s = ft_free(shell->s);
	shell->prompt = ft_free(shell->prompt);
	shell->path = (char **)ft_double_sfree((void **)shell->path);
	shell->en = (char **)ft_double_sfree((void **)shell->en);
	shell->aliace = (char **)ft_double_sfree((void **)shell->aliace);
	return (1);
}

static short	free_data_loc(t_loc *data)
{
	t_loc	*tmp;

	while (data)
	{
		tmp = data->next;
		data->decon_cmd = (char **)ft_double_sfree((void **)data->decon_cmd);
		data->tokens = ft_free(data->tokens);
		data->slice = ft_free(data->slice);
		data = ft_free(data);
		data = tmp;
	}
	return (2);
}

short	clean_shell(void)
{
	t_mshell	*shell;
	t_loc		**loc;
	short		err;

	err = 0;
	shell = ft_return_ptr(NULL, SYS);
	loc = ft_return_ptr(NULL, PARSE);
	if (shell)
		err += free_data_shell(shell);
	if (*loc)
		err += free_data_loc(*loc);
	return (err);
}
