/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:15:02 by anboisve          #+#    #+#             */
/*   Updated: 2024/04/08 17:19:36 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strmapft(char *s, int (*ft)(int))
{
	size_t	len;

	if (!s || !ft)
		return ;
	len = ft_strlen(s);
	while (len--)
		s[len] = ft(s[len]);
}