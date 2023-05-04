/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:18:25 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 14:30:13 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copy the src in dest of the size of dstsize
return the size of src
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s;

	if (!dst || !src)
		return (0);
	s = ft_strlen(src);
	if (s + 1 < dstsize)
		ft_memcpy(dst, ((char *)src), s + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, ((char *)src), dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (s);
}
