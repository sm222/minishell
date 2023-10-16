/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:09 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:25:10 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

/// @brief	try to find the file in local folder
/// @param	name	of the fontion
/// @param	out		return the path with name of the fontion
/// @return	1 if local, 2 if ./ fail FAIL, else M_FAIL
static int	test_local(char *name, char **out, mode_t *err)
{
	struct stat	test;

	lstat(name, &test);
	*err = test.st_mode;
	if (access(name, F_OK) == 0)
	{
		if (S_ISDIR(test.st_mode) || S_ISLNK(test.st_mode))
			return (NO_ASS);
		if (access(name, X_OK) != 0)
		{
			return (ERR_PD);
		}
		*out = ft_strdup(name);
		if (!*out)
			return (M_FAIL);
		return (1);
	}
	return (FAIL);
}

static int	look_perm(char **name, int err)
{
	if (access(*name, X_OK) != 0)
	{
		ft_printf(2, "%o"MS_NAME"%s %s\n", NULL, *name, strerror(errno));
		ft_free(*name);
		*name = NULL;
		return (ERR_PD);
	}
	return (err + 2);
}

static short	look_local_file(char **list, char *name)
{
	size_t	i;
	char	*new;

	i = 0;
	while (list && list[i])
	{
		ft_printf(NO_PRINT, "%o%s/%s", &new, list[i], name);
		if (access(new, F_OK) == 0)
		{
			ft_printf(2, "%o"MS_NAME"%s %s\n", NULL, new, strerror(errno));
			ft_free(new);
			return (ERR_NO_TXT);
		}
		ft_free(new);
		i++;
	}
	return (FAIL);
}

/// @brief	try to find the cmd
/// @param	name	name of the cmd
/// @param	out		return name + path, NULL if fail
/// @param	list	path of the system
/// @return	-1 if M_FAIL, FAIL if can't find path
/// @return	else return 1 or 2 for local file,
/// @return	3 and plus for the index were it find it
int	find_path(char *name, char **out, char **list, mode_t *err)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	*out = NULL;
	if (name && (name[0] == '.' || name[0] == '/'))
		return (test_local(name, out, err));
	if (name && !name[0])
		return (FAIL);
	while (list && list[i])
	{
		ft_printf(NO_PRINT, "%o%s/%s", &tmp, list[i], name);
		if (!tmp)
			return (M_FAIL);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			*out = tmp;
			return (look_perm(out, i));
		}
		tmp = ft_free(tmp);
		i++;
	}
	return (look_local_file(list, name));
}
