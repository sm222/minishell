/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:21:43 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:21:43 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static void	set_exit_flag(short flag)
{
	short	*ex;

	ex = ft_return_ptr(NULL, EX_F);
	if (ex)
		*ex = flag;
}

//9223372036854775807
static int	more_arg(char **av, int pec)
{
	long long	data;

	set_exit_flag(1);
	data = ft_atoll(av[1]);
	if (ft_ban(av[1], "-+" NUMBER) != 0 || ft_ban(av[1] + 1, NUMBER) != 0 || \
	ft_strlen(av[1]) > 19 || data > 9223372036854775807 || \
	data < -9223372036854775807)
	{
		ft_printf(STDERR_FILENO, \
		"%oMinishell: exit: %s: numeric argument required\n", NULL, av[1]);
		pec = 255;
	}
	else if (ft_strlen_double(av) >= 3)
	{
		ft_printf(STDERR_FILENO, \
		"%oMinishell: exit: too many arguments\n", NULL);
		set_exit_flag(0);
		pec = 1;
	}
	else
		pec = data;
	return (pec);
}

/// @brief	use to exit and return a err code
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
int	ft_exit(char **av, int re_in, int re_out, char **en)
{
	unsigned char	pec;
	int				tmp;

	pec = 0;
	(void)en;
	(void)re_in;
	(void)re_out;
	tmp = ft_atoi(av[0]);
	if (ft_strlen_double(av) == 1)
	{
		pec = tmp;
		set_exit_flag(1);
	}
	else
		pec = more_arg(av, tmp);
	return (pec);
}
