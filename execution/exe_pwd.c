/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:47 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/19 19:17:18 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

short	oldpwd(t_mshell *data)
{
	char	*new;
	char	**spl;

	ft_printf(NO_PRINT, "%oex OLDPWD=%s", &new, data->pwd);
	spl = ft_split(new, ' ');
	ft_export(spl, 0, 1, data->en);
	ft_double_sfree((void **)spl);
	ft_free(new);
	return (SUCCESS);
}

short	new_pwd(t_mshell *data)
{
	char	*new;
	char	**spl;
	char	*new_pwd;

	new_pwd = NULL;
	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
	{
		ft_printf(NO_PRINT, "%oex	PWD=%s", &new, new);
		spl = ft_split(new, '	');
		ft_export(spl, 0, 1, data->en);
		ft_double_sfree((void **)spl);
		ft_free(new);
	}
	return (SUCCESS);
}
