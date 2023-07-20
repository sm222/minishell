/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:30:55 by anboisve          #+#    #+#             */
/*   Updated: 2023/07/19 20:30:55 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_find(const char *src, const char *filter)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!src || !filter)
		return (-1);
	while (src[i])
	{
		j = 0;
		while (filter[j])
		{
			if (src[i] == filter[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
