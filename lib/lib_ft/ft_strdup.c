/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:41:52 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 15:49:00 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief dup a string
/// @return new string
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
