/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:19:43 by anboisve          #+#    #+#             */
/*   Updated: 2024/04/04 09:06:25 by anboisve         ###   ########.fr       */
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
	if (en && en[0])
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
	char	*t;

	if (ft_strncmp(dir, "-", 2) == 0)
	{
		t = find_name(en, "OLDPWD=");
		if (t)
		{
			ft_printf(re_out, "%o%s\n", NULL, t);
			dir = t;
		}
		else
		{
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
			return (EXIT_FAILURE);
		}
	}
	if (chdir(dir))
	{
		ft_printf(STDERR_FILENO, "%ocd: %s: %s\n", NULL, \
	strerror(errno), dir);
		return (EXIT_FAILURE);
	}
	return (0);
}

static size_t	find_file(char *pwd)
{
	char	find_git[PWD_GIT];
	char	*tmp;

	ft_bzero(find_git, PWD_GIT);
	ft_memcpy(find_git, pwd, ft_strlen(pwd));
	while (*pwd)
	{
		ft_memcpy(find_git + ft_strlen(pwd), "/.git/HEAD", 11);
		if (access(find_git, F_OK) == 0)
			return (ft_strlen(find_git));
		tmp = ft_strrchr(pwd, PATH_SEP);
		if (tmp && *tmp)
			*tmp = 0;
		else
			return (0);
	}
	return (0);
}

static int	cd_git(void)
{
	char	pwd[PATH_MAX + 1];
	size_t	i;
	int		err;

	err = 2;
	ft_bzero(pwd, PATH_MAX + 1);
	getcwd(pwd, PATH_MAX);
	i = find_file(pwd);
	pwd[i] = 0;
	if (*pwd)
		err = chdir(pwd);
	else
		ft_printf(2, "%o"MS_NAME"\b: cd: no .git find\n", NULL);
	return (err);
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
	if (len == 1 || ft_strncmp(av[1], "\0", 1) == 0)
		return (get_to_user(en));
	if (len == 2 && ft_strncmp(av[1], "-g", 3) == 0)
		return (cd_git());
	return (goto_dir(av[1], en, re_out));
}
