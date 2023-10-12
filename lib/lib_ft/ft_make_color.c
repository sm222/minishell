/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:38:16 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/12 10:53:27 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_make_color(short r, short g, short b)
{
	char	*color;

	color = NULL;
	ft_printf(1, "%o\x1b[38;2;%d;%d;%dm", color, r, g, b);
	return (color);
}
