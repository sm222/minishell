/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:54:43 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/23 17:45:15 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

/*
static int	read_file(char ***aliace, char *name)
{
	
}
*/

void	set_alias(t_mshell *shell)
{
	char	**av;
	//int		fd;

	shell->alias = ft_split("a", '\b');
	ft_return_ptr(shell->alias, ALIAS_VAR);
	av = ft_split("ms\b-r\b"CONPILE_DIR"/.config/.msrc", '\b');
	ft_ms(av, 0, 1, shell->en);
	//if (ft != 0)
	//{
	//	ft_printf(2, "%o%d "MS_NAME"\b: making /.config/.msrc in "CONPILE_DIR"\n", NULL, ft);
	//	fd = open(CONPILE_DIR"/.config/.msrc", O_CREAT | O_TRUNC | O_RDWR, 0644);
	//	if (fd)
	//		ft_putstr_fd("echo in "CONPILE_DIR"/.config/.msrc you can edit me for costum parm at openig \n", fd);
	//		ft_putstr_fd("echo if you want to mute that message put \"'#'\" in front of the line", fd);
	//	close(fd);
	//}
	ft_double_sfree((void **)av);
}
