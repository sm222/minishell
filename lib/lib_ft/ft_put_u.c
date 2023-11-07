/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:01:10 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/07 15:24:11 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
print unsigned int
*/
int	ft_put_u(unsigned int nb, int fd)
{
	int		size;
	char	*tmp;

	tmp = ft_ulltoa(nb, 10);
	size = ft_putstr_fd(tmp, fd);
	ft_free(tmp);
	return (size);
}
