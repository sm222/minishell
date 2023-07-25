/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:06:00 by anboisve          #+#    #+#             */
/*   Updated: 2023/07/25 11:08:22 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief use to
/// @param ptr input, set to NULL if you want just the output
/// @param i index of the adrres you want
/// @return pointer to the variable or struc
void	*ft_return_ptr(void *ptr, int i)
{
	static void	*mem[10];

	if (i == -1)
	{
		ft_bzero(mem, sizeof(void *[10]));
		return (NULL);
	}
	if (i < 0 || i > 9)
		return (NULL);
	if (ptr)
		mem[i] = ptr;
	return (mem[i]);
}
