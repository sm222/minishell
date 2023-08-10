/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:01:27 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/10 09:41:58 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *s)
{
	long long	rez;
	short		min;
	size_t		i;

	if (!s)
		return (0);
	min = 1;
	rez = 0;
	i = 0;
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			min *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		rez = rez * 10 + (s[i++] - '0');
	return (rez * min);
}
