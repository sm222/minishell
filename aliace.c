/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliace.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:54:43 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/07 23:28:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	set_aliace(t_mshell *shell)
{
	shell->aliace = ft_split("a a a a", ' ');
}
