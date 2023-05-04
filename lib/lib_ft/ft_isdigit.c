/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:11:00 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 12:21:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
return the char if it is a char betwen 0 and 9 else return 0
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}
