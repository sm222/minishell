/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:21:16 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:21:16 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/// @brief	give the environment of the shell
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return	errcode
int	ft_env(char **av, int re_in, int re_out, char **en)
{
	size_t	i;

	(void)re_in;
	i = 0;
	if (!av)
	{
		ft_putstr_fd("env: too many arguments\n", 2);
		return (1);
	}
	while (en && en[i])
	{
		if (ft_strchr(en[i], '='))
			ft_printf(re_out, "%o%s\n", NULL, en[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
