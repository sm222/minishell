/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:06:00 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/12 10:52:46 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief use to
/// @param ptr input, set to NULL if you want just the output
/// @param i index of the adrres you want
/// @return pointer to the variable or struc
void	*ft_return_ptr(void *ptr, int i)
{
	static void	*mem[RETURN_PTR_MAX];

	if (i == -1)
	{
		ft_bzero(mem, sizeof(void *[RETURN_PTR_MAX]));
		return (NULL);
	}
	if (i < 0 || i > RETURN_PTR_MAX - 1)
		return (NULL);
	if (ptr)
		mem[i] = ptr;
	return (mem[i]);
}
