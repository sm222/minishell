/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:12:13 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 11:52:09 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_select(va_list list, char c, int fd)
{
	char	*s;

	if (c == 's')
	{
		s = va_arg(list, char *);
		if (!s)
			return (ft_putstr_fd("(null)", fd));
		return (ft_putstr_fd(s, fd));
	}
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg(list, int), fd));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(list, int), fd));
	else if (c == 'p')
		return (ft_put_p(va_arg(list, unsigned long), fd));
	else if (c == '%')
		return (ft_putchar_fd('%', fd));
	else if (c == 'x' || c == 'X')
		return (ft_put_hex(va_arg(list, unsigned int), c, fd));
	else if (c == 'u')
		return (ft_put_u(va_arg(list, unsigned int), fd));
	return (0);
}

/// @brief
/// @param str 
/// @param  
/// @return 
int	ft_printf(int fd, const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		total;

	total = 0;
	i = 0;
	if (!str)
		return (0);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			total += ft_putchar_fd(str[i], fd);
		else
		{
			if (str[++i] == 0)
				continue ;
			total += ft_print_select(arg, str[i], fd);
		}
		i++;
	}
	va_end(arg);
	return (total);
}

/*
ft_printf.c
ft_put_hex.c
ft_put_p.c
ft_put_u.c

ft_ulltoa.c
*/