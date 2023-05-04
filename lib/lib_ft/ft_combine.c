/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:44:12 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/15 14:03:32 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_add_c_to_s(char *s, char c)
{
	char	*new;
	int		i;

	i = ft_strlen(s);
	new = ft_calloc(i + 2, sizeof(char));
	ft_memmove(new, s, i);
	new[i] = c;
	ft_safe_free(s);
	return (new);
}

static char	*ft_add_arg(va_list list, char type)
{
	if (type == 's' || type == 'S')
		return (va_arg(list, char *));
	else if (type == 'd' || type == 'i')
		return (ft_itoa(va_arg(list, int)));
	else if (type == 'u')
		return (ft_ulltoa(va_arg(list, unsigned int), 10));
	else if (type == 'x')
		return (ft_ulltoa(va_arg(list, unsigned long), 16));
	else if (type == '%')
		return (ft_strdup("%"));
	return (NULL);
}

static char	*ft_add_str(va_list list, char type, char *s)
{
	char	*tmp;

	if (type == 'c')
		return (ft_add_c_to_s(s, va_arg(list, int)));
	tmp = ft_add_arg(list, type);
	s = ft_strfjoin(s, tmp);
	if (type != 's')
		ft_safe_free(tmp);
	return (s);
}

/*
	combine is use like a printf but give you back the result in a char *
		s = str 
		S = str but will free it for you
		d || i for int
		x = hexadecimal
		%% = add one %
*/
char	*ft_combine(char *s, ...)
{
	size_t	i;
	char	*new;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	new = ft_calloc(1, sizeof(char));
	while (s && s[i])
	{
		if (s[i] != '%')
		{
			new = ft_add_c_to_s(new, s[i]);
			if (!new)
				return (NULL);
		}
		else
		{
			new = ft_add_str(arg, s[++i], new);
			if (!new)
				return (NULL);
		}
		i++;
	}
	va_end(arg);
	return (new);
}
