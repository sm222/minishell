/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:28:02 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:28:03 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"
#include "../lib/lib_ft/libft.h"

/// @brief	use to print err msg
/// @param	type	PERROR	use perror
/// @param	type	NO_FREE	use ft_printf
/// @param	type	DO_FREE	use ft_printf and free it
/// @param	err	
/// @param	msg	
/// @return	err code
int	err_msg(short type, int err, char *msg)
{
	if (type == PERROR)
		perror(msg);
	if (type == NO_FREE)
		ft_printf(STDERR_FILENO, "%s\n", msg);
	if (type == DO_FREE)
		ft_printf(STDERR_FILENO, "%S\n", msg);
	return (err);
}

int	debug(int err, char *msg, char *file)
{
	int		fd;
	char	*t;

	ft_printf(-1, "%o%d %s\n", &t, err, msg);
	if (file)
	{
		fd = open(file, O_CREAT | O_APPEND | O_RDWR, 0644);
		if (fd == -1)
		{
			ft_putstr_fd("can't, make debug file\n", 2);
			return (DEBUG_ERR);
		}
		ft_putstr_fd(t, fd);
		close(fd);
	}
	else
		ft_putstr_fd(t, 2);
	ft_free(t);
	return (err);
}
