/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:54:43 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/24 08:42:50 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

/*
static int	read_file(char ***aliace, char *name)
{
	
}
*/

void	set_alias(t_mshell *shell)
{
	char	**av;

	shell->alias = ft_calloc(1, sizeof(char *));
	ft_return_ptr(shell->alias, ALIAS_VAR);
	av = ft_split("ms\b-r\b"CONPILE_DIR"/.config/.msrc", '\b');
	ft_ms(av, 0, 1, shell->en);
	ft_double_sfree((void **)av);
}
