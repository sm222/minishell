/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:19:43 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:19:46 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"
#include "../../include/structure.h"

static char	*find_name(char **en, char *name)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(name);
	while (en && en[i])
	{
		if (ft_strncmp(en[i], name, len) == 0)
			return (en[i] + len);
		i++;
	}
	return (NULL);
}

/// @brief	try to move in the HOME path
/// @return	2 if fail, or chdir value
static int	get_to_user(char **en)
{
	char	*env;
	int		err;

	env = NULL;
	if (en)
		env = find_name(en, "HOME=");
	if (!env || !*env)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
	}
	err = chdir(env);
	if (err)
		ft_printf(STDERR_FILENO, "%ocd: %s: %s\n", \
		NULL, strerror(errno), env);
	return (err);
}

/// @brief		try to go to char* dir
/// @param	dir 	directory
/// @return			err code
static int	goto_dir(char *dir, char **en, int re_out)
{
	int		err;
	char	*t;

	if (ft_strncmp(dir, "", 1) == 0)
		return (0);
	if (ft_strncmp(dir, "-", 2) == 0)
	{
		t = find_name(en, "OLDPWD=");
		ft_printf(re_out, "%o%s\n", NULL, t);
		if (t)
			dir = t;
		else
		{
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
			return (EXIT_FAILURE);
		}
	}
	err = chdir(dir);
	if (err)
	{
		ft_printf(STDERR_FILENO, "%ocd: %s: %s\n", NULL, \
	strerror(errno), dir);
		return (EXIT_FAILURE);
	}
	return (0);
}

/// @brief		move to a dir
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
int	ft_cd(char **av, int re_in, int re_out, char **en)
{
	size_t	len;

	(void)re_in;
	len = ft_strlen_double(av);
	if (len == 1)
		return (get_to_user(en));
	return (goto_dir(av[1], en, re_out));
}
