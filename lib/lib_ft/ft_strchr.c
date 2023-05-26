/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:32:07 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 15:48:31 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief look in a str for a char
/// @param s str
/// @param c target
/// @return adress of the targer
char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		n;

	if (!s)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}
