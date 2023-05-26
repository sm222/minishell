/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:04:58 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 11:42:02 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief set the memory to c
/// @param b 
/// @param c 
/// @param len 
/// @return 
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	if (!b)
		return (NULL);
	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = c;
	return (b);
}
