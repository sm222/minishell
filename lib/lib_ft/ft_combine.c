/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:44:12 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:30:16 by anboisve         ###   ########.fr       */
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
	ft_free(s);
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
		ft_free(tmp);
	return (s);
}

/// @brief make a news string like a printf and return it
/// @param s flag like a printf
/// @details s = str 
/// @details S = str but will free it for you
/// @details d || i for int
/// @details x = hexadecimal
/// @details %% = add one %
/// @return new str
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
