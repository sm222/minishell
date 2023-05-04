/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:01:20 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 11:32:02 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
take a str and give you back number in int
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	flp;
	int	val;

	if (!str)
		return (0);
	val = 0;
	flp = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flp *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		val = val * 10 + (str[i++] - '0');
	return (val * flp);
}
