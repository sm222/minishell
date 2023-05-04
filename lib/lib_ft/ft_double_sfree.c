/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_sfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:06:56 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 12:12:47 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
free double ptr array
return NULL
*/
void	**ft_double_sfree(void **ptr)
{
	size_t	i;

	i = 0;
	while (ptr && ptr[i])
		free(ptr[i++]);
	ft_safe_free(ptr);
	return (NULL);
}
