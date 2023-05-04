/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:11:22 by anboisve          #+#    #+#             */
/*   Updated: 2023/04/16 11:05:47 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
return the char if it is a char else return 0
*/

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c);
	else if (c >= 'A' && c <= 'Z')
		return (c);
	return (0);
}
