/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:39 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 12:22:02 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
return the char if it is a printable else return 0
*/
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (c);
	return (0);
}
