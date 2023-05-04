/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:41:52 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 14:21:42 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
dup a str in a new
*/
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	new = ft_calloc(i++ + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (--i >= 0)
		new[i] = s1[i];
	return (new);
}
