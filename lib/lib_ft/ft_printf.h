/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:13:03 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/08 14:47:54 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef struct s_printf
{
	va_list	arg;
	size_t	i;
	int		total;
	char	**out;
}	t_printf;

int		ft_printf(int fd, char *str, ...);
int		ft_put_p(unsigned long p, int fd);
char	*ft_ulltoa(unsigned long long nb, int base);
int		ft_put_hex(unsigned int nb, char maj, int fd);
int		ft_put_u(unsigned int nb, int fd);

#endif
