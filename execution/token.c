/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:26:19 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:26:21 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

/// @brief	create a new node
/// @param	flag		binary
/// @param	redi_in		in file
/// @param	redi_out	out file
/// @return	new node, NULL if malloc fail
t_token	*make_token(int flag, int redi_in, int redi_out)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->redi_in = redi_in;
	new->redi_out = redi_out;
	new->mode = flag;
	new->redi_doc = 0;
	return (new);
}
