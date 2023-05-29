/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:46:45 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/29 11:14:31 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
realloc give you the size of the memory you want on the same poiter
*/
void	*ft_realloc(void *old, size_t count, size_t len, size_t new_len)
{
	void	*new;

	if (!old)
		return (NULL);
	new = ft_calloc(count, new_len);
	if (!new)
		return (NULL);
	if (len <= new_len)
		ft_memcpy(new, old, count * len);
	else
		ft_memcpy(new, old, count * new_len);
	ft_free(old);
	return (new);
}
