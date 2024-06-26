/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_git.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:13:56 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/16 17:06:44 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include "lib/lib_ft/libft.h"
#include <limits.h>

static char	*edit_git(char *in)
{
	size_t	i;

	i = ft_strlen(in) - 1;
	while (i && in[i] != '/')
		i--;
	if (i == 0)
		return (NULL);
	return (ft_strdup(in + i + 1));
}

/// @brief find number of '/' in getcwd()
/// @param  void
/// @return n of '/'
static int	cont_c(void)
{
	int		i;
	int		n;
	char	pwd[PATH_MAX + 1];

	i = 0;
	n = 0;
	ft_bzero(pwd, PATH_MAX + 1);
	getcwd(pwd, PATH_MAX);
	while (pwd[i])
	{
		if (pwd[i] == '/')
			n++;
		i++;
	}
	return (n);
}

static char	*find_file(void)
{
	char	*find;
	char	*tmp;
	int		i;

	i = cont_c();
	find = ft_strdup(".git/HEAD");
	if (!find)
		return (NULL);
	while (access(find, F_OK) != 0)
	{
		if (i-- == 0)
			break ;
		ft_printf(NO_PRINT, "%o../%s", &tmp, find);
		ft_free(find);
		if (!tmp)
			return (NULL);
		find = tmp;
	}
	if (i == 0)
	{
		ft_free(find);
		return (NULL);
	}
	return (find);
}

void	find_git(t_mshell *shell)
{
	int		fd;
	char	*line;
	char	*out;
	char	*t;

	shell->git_status = NULL;
	out = NULL;
	t = find_file();
	fd = open(t, O_RDONLY);
	if (fd > 0)
	{
		line = "a";
		while (line)
		{
			line = get_next_line(fd);
			out = ft_strfjoin(out, line);
			ft_free(line);
		}
		shell->git_status = edit_git(out);
		if (shell->git_status)
			shell->git_status[ft_strlen(shell->git_status) - 1] = 0;
		ft_free(out);
		close(fd);
	}
	ft_free(t);
}
