/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:51:56 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/23 09:38:24 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	set_pec_to(int val)
{
	int		*pec;

	pec = ft_return_ptr(NULL, PEC);
	*pec = val;
}

int	bad_con_err(short *to_set, short val, int err, char c)
{
	*to_set = val;
	set_pec_to(err);
	ft_printf(2, "%o"MS_NAME"\b: "SENUT" `%c\'\n", NULL, c);
	return (FAIL);
}
