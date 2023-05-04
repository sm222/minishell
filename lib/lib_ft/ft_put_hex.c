/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:51:22 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/30 12:57:07 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
put number in hex
if maj = X, it will output in maj
*/
int	ft_put_hex(unsigned int nb, char maj)
{
	int		size;
	char	*tmp;

	tmp = ft_ulltoa(nb, 16);
	size = ft_strlen(tmp) + 1;
	if (maj == 'X')
		while (size--)
			tmp[size] = ft_toupper(tmp[size]);
	size = ft_putstr_fd(tmp, STDOUT_FILENO);
	ft_safe_free(tmp);
	return (size);
}
