/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:46:45 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:31:50 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
realloc give you the size of the memory you want on the same poiter
*/
void	*ft_realloc(void *old, size_t count, size_t size, size_t new_size)
{
	void	*new;

	if (!old)
		return (NULL);
	new = ft_calloc(count, new_size);
	if (!new)
		return (NULL);
	if (size > new_size)
		ft_memcpy(new, old, count * new_size);
	else
		ft_memcpy(new, old, count * size);
	ft_free(old);
	return (new);
}
