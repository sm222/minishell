/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:46:35 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 11:38:15 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief move memorry form src to dest
/// @param dst 
/// @param src 
/// @param len memory len in byte
/// @return adress of dest
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL || src == NULL)
		return (NULL);
	if (src < dst)
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
