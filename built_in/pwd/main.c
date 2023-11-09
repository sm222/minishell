/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:22:41 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/08 20:38:27 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

int	main(int ac, char **av, char **en)
{
	char	pwd[PATH_MAX];

	(void)ac;
	getcwd(pwd, PATH_MAX);
	av[0] = pwd;
	return (ft_pwd(av, 0, 1, en));
}
