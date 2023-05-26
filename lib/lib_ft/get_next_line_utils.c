/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:34:37 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:29:51 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
take a safefree and s2 and join
free safefree
return the copy
*/
char	*ft_strfjoin(char *safefree, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = ft_strlen(safefree);
	s2_i = ft_strlen(s2);
	new = ft_calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = ft_free(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = safefree[s1_i];
	if (*new == 0)
		new = ft_free(new);
	return (ft_free(safefree), new);
}
