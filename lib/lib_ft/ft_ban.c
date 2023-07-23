/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ban.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:50:03 by anboisve          #+#    #+#             */
/*   Updated: 2023/07/20 21:50:03 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_ban(const char *src, const char *list)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!src || !list)
		return (-1);
	i = 0;
	len = ft_strlen(list);
	while (src[i])
	{
		j = 0;
		while (list[j])
		{
			if (src[i] == list[j])
				break ;
			j++;
		}
		if (j == len)
			return (1);
		i++;
	}
	return (0);
}
