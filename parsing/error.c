/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:24:19 by brheaume          #+#    #+#             */
/*   Updated: 2023/10/19 14:01:39 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_error_file(char *path, int mode)
{
	if (mode == NO_FILE_OUT)
		ft_printf(2, "%o"MS_NAME"\b: no file given for output redirection\n", NULL);
	else if (mode == NO_ACCESS)
		ft_printf(2, "%o"MS_NAME"\b: %s: can't access file\n", NULL, path);
	else if (mode == NO_FILE && !path)
		ft_printf(2, "%o"MS_NAME"\b: %s: no such file or directory\n", NULL, path);
	else if (mode == NO_FILE)
		ft_printf(2, "%o"MS_NAME"\b: %s: no such file or directory\n", NULL, path);
	else if (mode == NO_FILE_IN)
		ft_printf(2, "%o"MS_NAME"\b: no file given for input redirection\n", NULL);
	ft_set_error_code(1);
	return (INCORRECT);
}
