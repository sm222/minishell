/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:32:07 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 14:02:18 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
look for a char in a str and return the adress
else return NULL
*/
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
