/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:34 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 16:04:19 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief return the len of a str
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
