/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 09:01:49 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:51:44 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief look for a nuber in memory
/// @param s memory array
/// @param c seek number
/// @param n byte size
/// @return adress were it was find
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (++i < n)
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
	return (NULL);
}
