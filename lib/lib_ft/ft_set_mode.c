/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:50:32 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/13 09:24:37 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief look if you are in ' ' or " "
/// @param c last char inter, if -1 reset, 0 return in what type you are
/// @return
short	ft_set_mode(char c)
{
	static short	last = 0;

	if (c == -1)
		last = 0;
	if (c == 0)
		return (last);
	if (last == 0 && c == '"')
		last = 2;
	else if (last == 2 && c == '"')
		last = 0;
	else if (last == 0 && c == '\'')
		last = 1;
	else if (last == 1 && c == '\'')
		last = 0;
	return (last);
}
