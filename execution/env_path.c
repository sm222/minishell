/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:29 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/20 18:10:27 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

/// @brief copy the env
/// @param env were the data will be store &en
/// @param old 
/// @return err code
static short	new_run_env(char ***env, char **old)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (old && old[i])
	{
		if (ft_strchr(old[i], '='))
		{
			(*env)[j] = ft_strdup(old[i]);
			if (!(*env)[j])
				return (M_FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}


/// @brief use to give new env to exeve witout the variable with no value
/// @param en env of minishell
/// @return new env
char	**ex_en_new(char **en)
{
	char	**new;
	size_t	i;
	size_t	j;

	new = NULL;
	i = 0;
	j = 0;
	while (en && en[i])
	{
		if (ft_strchr(en[i], '='))
			j++;
		i++;
	}
	new = ft_calloc(j + 1, sizeof(char *));
	if (!new)
	{
		perror("minishell : ft_calloc");
		return (NULL);
	}
	if (new_run_env(&new, en) == M_FAIL)
		new = (char **)ft_double_sfree(((void **)new));
	return (new);
}

/// @brief make new path befor trying to find the exe
/// @param shell data
/// @return err code
short	make_new_path(t_mshell *shell)
{
	size_t	i;
	int		len;

	if (!shell)
		return (BAD_ARGS);
	if (shell->path)
		shell->path = (char **)ft_double_sfree((void **)shell->path);
	i = 0;
	len = ft_strlen(PATH_BIN_S);
	while (shell->en && shell->en[i])
	{
		if (ft_strncmp(PATH_BIN_S, shell->en[i], len) == 0)
		{
			shell->path = ft_split(shell->en[i] + len, PATH_SPLIT);
			if (!shell->path)
				return (M_FAIL);
			return (SUCCESS);
		}
		i++;
	}
	shell->path = ft_split(" : ", ':');
	if (!shell->path)
		return (M_FAIL);
	return (SUCCESS);
}
