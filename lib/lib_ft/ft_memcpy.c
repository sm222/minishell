/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:46:16 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:57:02 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy memory to a new ptr
/// @param dst were the copy go
/// @param src input of the copy
/// @param n byte size
/// @return new copy
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (dst);
	i = -1;
	while (++i < n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}
