/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_sfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:06:56 by anboisve          #+#    #+#             */
/*   Updated: 2024/04/19 15:10:40 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief use to free a double pointer
/// @param ptr input
/// @return NULL
void	**ft_double_sfree(void **ptr)
{
	size_t	i;

	i = 0;
	while (ptr && ptr[i])
	{
		ptr[i] = ft_free(ptr[i]);
		i++;
	}
	ft_free(ptr);
	return (NULL);
}
