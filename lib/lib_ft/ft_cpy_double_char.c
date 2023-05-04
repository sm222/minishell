/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_double_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:53:12 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 13:42:54 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copy a doubble char pointer on a new ptr
*/
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
