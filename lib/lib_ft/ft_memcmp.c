/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 09:41:07 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:55:42 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief compare memory and return the diference
/// @param s1 array 1
/// @param s2 array 2
/// @param n size of the array
/// @return dif
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2 || n == 0)
		return (0);
	while (i < n -1 && (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
