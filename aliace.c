/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliace.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:54:43 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/12 00:48:09 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

/*
static int	read_file(char ***aliace, char *name)
{
	
}
*/

void	set_aliace(t_mshell *shell)
{
	char	**av;

	shell->aliace = ft_split("a a a a", ' ');
	av = ft_split("ms\b-r\b.config/.msrc", '\b');
	ft_ms(av, 0, 1, shell->en);
	ft_double_sfree((void **)av);
}
