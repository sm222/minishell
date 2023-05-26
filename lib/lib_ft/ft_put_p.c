/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:09:21 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 11:48:16 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
print a adress like printf
*/
int	ft_put_p(unsigned long p, int fd)
{
	char	*tmp;
	int		size;

	size = ft_putstr_fd("0x", fd);
	tmp = ft_ulltoa((unsigned long)p, 16);
	size += ft_putstr_fd(tmp, fd);
	if (tmp)
		ft_free(tmp);
	return (size);
}
