/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_git.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:13:56 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/05 13:19:08 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include "lib/lib_ft/libft.h"

void	find_git(t_mshell *shell)
{
	//char	**git;
	int		fd;
	char 	*line;
	char	*out;
	
	(void)shell;
	out = NULL;
	if (access(".git/config", F_OK) == 0)
	{
		fd = open(".git/config", O_RDONLY);
		if (fd > 0)
		{
			line = "a";
			while (line)
			{
				line = get_next_line(fd);
				out = ft_strfjoin(out, line);
				ft_free(line);
			}
			printf("%s\n", out);
			ft_free(out);
			close(fd);
		}
	}
}
