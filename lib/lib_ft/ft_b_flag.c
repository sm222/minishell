/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:44:15 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/25 11:24:48 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_b_print(int f, int fd)
{
	char	*s;

	ft_printf(-1, "%o%d%d%d%d%d%d%d%d\n",
		&s,
		ft_b_flag_read(f, 7),
		ft_b_flag_read(f, 6),
		ft_b_flag_read(f, 5),
		ft_b_flag_read(f, 4),
		ft_b_flag_read(f, 3),
		ft_b_flag_read(f, 2),
		ft_b_flag_read(f, 1),
		ft_b_flag_read(f, 0));
	if (!s)
	{
		ft_putstr_fd("malloc fail\n", 2);
		return ;
	}
	ft_putstr_fd(s, fd);
	ft_free(s);
}

short	ft_b_flag_read(int flag, int byte)
{
	if (byte > 7 || byte < 0)
		return (-1);
	return (flag >> byte & 1);
}

void	ft_b_toggle_flag(int *flag, int pos)
{
	int	i;

	i = 2;
	if (pos < 0 || pos > 7)
		return ;
	while (--pos)
		i *= 2;
	*flag ^= i;
}

void	ft_b_set_flag(int *flag, int pos, char tf)
{
	int	i;

	i = 2;
	if (pos < 0 || pos > 7)
		return ;
	if (tf != ft_b_flag_read(*flag, pos))
	{
		while (--pos)
			i *= 2;
		*flag ^= i;
	}
}
