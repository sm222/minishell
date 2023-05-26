/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:00:50 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:38:46 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief malloc and bzero the memory
/// @param count number of element
/// @param size size of the element
/// @return new memory
void	*ft_calloc(size_t count, size_t size)
{
	void	*new;

	new = NULL;
	new = malloc(count * size);
	if (!new)
		return (NULL);
	ft_bzero(new, count * size);
	return (new);
}
