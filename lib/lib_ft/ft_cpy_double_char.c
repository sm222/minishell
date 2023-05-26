/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_double_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:53:12 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:18:55 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy a double array
/// @param str input
/// @return new double array
char	**ft_cpy_double_char(char **str)
{
	size_t	i;
	size_t	j;
	char	**new;

	i = 0;
	j = 0;
	new = NULL;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	new = ft_calloc(i + 1, sizeof(char *));
	while (j < i)
	{
		new[j] = ft_strdup(str[j]);
		j++;
	}
	return (new);
}
