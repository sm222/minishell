/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:19:56 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 13:20:38 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	free only if pointer is not NULL
	return NULL
*/
void	*ft_safe_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}
