/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:32:18 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/20 18:07:51 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

/// @brief make the path double array in 'data->path'
/// @param data take 'mshell' struct
/// @return FAIL if can't find 'PATH='
/// @return if split fail
/// @return else SUCCESS
int	get_env_path(t_mshell *data)
{
	size_t	i;

	i = 0;
	data->path = NULL;
	while (data->en && data->en[i])
	{
		if (ft_strncmp(data->en[i], PATH_BIN_S, ft_strlen(PATH_BIN_S)) == 0)
		{
			data->path = ft_split(data->en[i], PATH_SPLIT);
			if (!data->path)
				return (M_FAIL);
			return (SUCCESS);
		}
		i++;
	}
	return (SUCCESS);
}
