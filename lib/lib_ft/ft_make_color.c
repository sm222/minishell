/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:38:16 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/11 23:17:58 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
\x1b[38;5;[n]m is foreground
\x1b[48;5;[n]m is background

\x1b[38;2;r;g;bm - foreground
\x1b[48;2;r;g;bm - background

The first 16 entries are the basic color table again

The next 216 entries are a 6x6x6 cube

The final 24 entries are a grayscale ramp
*/

char	*ft_make_color_pro(short rgb[3], char bf)
{
	char	*color;

	(void)rgb;
	(void)bf;
	color = NULL;
	return (color);
}

char	*ft_make_color(short r, short g, short b)
{
	char	*color;

	color = NULL;
	ft_printf(1, "%o\001\e[38;2;%d;%d;%dm\002", color, r, g, b);
	return (color);
}
