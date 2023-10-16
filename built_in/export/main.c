/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:22:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:22:33 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	main(int ac, char **av, char **en)
{
	char	**en_c;
	int		err;

	(void)ac;
	en_c = ft_cpy_double_char(en);
	ft_return_ptr(en_c, ENV_C);
	if (!en_c)
		return (2);
	err = ft_export(av, 0, 1, en_c);
	ft_double_sfree((void **)ft_return_ptr(NULL, ENV_C));
	return (err);
}
