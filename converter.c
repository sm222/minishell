/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:32:23 by anboisve          #+#    #+#             */
/*   Updated: 2024/05/19 13:04:43 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

static short	find_name(const char *name)
{
	if (
		ft_strncmp(name, EXPORT, ft_strlen(EXPORT) + 1) == 0 || \
		ft_strncmp(name, UNSET, ft_strlen(UNSET) + 1) == 0 || \
		ft_strncmp(name, FT_ECHO, ft_strlen(FT_ECHO) + 1) == 0 || \
		ft_strncmp(name, EXIT, ft_strlen(EXIT) + 1) == 0 || \
		ft_strncmp(name, PWD, ft_strlen(PWD) + 1) == 0 || \
		ft_strncmp(name, ENV, ft_strlen(ENV) + 1) == 0 || \
		ft_strncmp(name, CD, ft_strlen(CD) + 1) == 0 || \
		ft_strncmp(name, ALIAS, ft_strlen(ALIAS) + 1) == 0 || \
		ft_strncmp(name, MS, ft_strlen(MS)) == 0 )
		return (BUILT_IN_FLAG);
	return (0);
}

static int	find_buit_in(char *name)
{
	int		flag;
	char	*tmp;
	size_t	i;

	flag = 0;
	i = 0;
	tmp = ft_strdup(name);
	if (!tmp)
		return (flag);
	while (tmp[i])
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	flag = find_name(tmp);
	free(tmp);
	return (flag);
}

short	converter(char *in, t_cmd **list)
{
	t_loc	*tmp;
	t_loc	*nav;
	int		flag;

	if (!in || !list)
		return (BAD_ARGS);
	nav = ft_parsing(in);
	if (!nav)
	{
		return (FAIL);
	}
	while (nav)
	{
		flag = 0;
		if (nav->decon_cmd && nav->decon_cmd[0])
			flag = find_buit_in(nav->decon_cmd[0]);
		nav->tokens->mode = flag;
		cmd_make_node_last(list, nav->decon_cmd, nav->tokens);
		tmp = nav;
		nav = nav->next;
		ft_free(tmp);
	}
	return (SUCCESS);
}
