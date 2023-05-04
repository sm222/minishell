/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:19:59 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 14:37:55 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
find the char in a s
*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (i > 0)
	{
		if (((char *)s)[i] == (char)c)
			return (((char *)s) + i);
		i--;
	}
	return (NULL);
}
