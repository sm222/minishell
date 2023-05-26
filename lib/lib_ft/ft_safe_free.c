/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:27:28 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:28:06 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief free a pointer if the adrres in not NULL
/// @param p input
/// @return NULL
void	*ft_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}
