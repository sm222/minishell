/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:05:04 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/12 10:53:17 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rfind_char(char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i + 1)
	{
		if (s[i] == c)
			return (s + i + 1);
		i--;
	}
	return (s);
}

char	*ft_find_char(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}
