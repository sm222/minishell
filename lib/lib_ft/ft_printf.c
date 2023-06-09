/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:12:13 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/09 10:07:34 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_free(char *s, char c, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s, len);
	if (c == 'S')
		free(s);
	return (len);
}

static int	ft_print_select(va_list list, char c, int fd)
{
	char	*s;

	if (c == 's' || c == 'S')
	{
		s = va_arg(list, char *);
		if (!s)
			return (ft_putstr_fd("(null)", fd));
		return (print_free(s, c, fd));
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

int	make_new_str(char *s, va_list arg, char **out)
{
	*out = NULL;
	*out = ft_combine(s + 2, arg);
	return (ft_strlen(*out));
}

/// @brief use to print like printf, "%o" give a adresse of a char *
/// @brief make a news string like a printf and return it
/// @param fd chose output
/// @details s = str 
/// @details S = str but will free it for you
/// @details d || i for int
/// @details x = hexadecimal
/// @details %% = add one %
/// @return len
int	ft_printf(int fd, char *str, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(t_printf));
	if (!str)
		return (0);
	va_start(pf.arg, str);
	if (ft_strncmp(str, "%o", 2) == 0)
		return (make_new_str(str, pf.arg, va_arg(pf.arg, char **)));
	while (str[pf.i])
	{
		if (str[pf.i] != '%')
			pf.total += ft_putchar_fd(str[pf.i], fd);
		else
		{
			if (str[++pf.i] == 0)
				continue ;
			pf.total += ft_print_select(pf.arg, str[pf.i], fd);
		}
		pf.i++;
	}
	va_end(pf.arg);
	return (pf.total);
}

/*
ft_printf.c
ft_put_hex.c
ft_put_p.c
ft_put_u.c

ft_ulltoa.c
*/