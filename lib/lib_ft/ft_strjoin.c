/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:33:59 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 15:54:41 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief combine 2 string togerter, if the 2 of them is NULL, return NULL
/// @param s1 input 1
/// @param s2 input 2
/// @return new str of the new str
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = ft_calloc(i + j + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (j--)
		new[j + i] = s2[j];
	while (i--)
		new[i] = s1[i];
	return (new);
}
