/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:32:23 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/07 11:13:06 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in/edit/edit.h"
#include "include/minishell.h"

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
	if (ft_strncmp(tmp, EXPORT, ft_strlen(EXPORT) + 1) == 0 || \
		ft_strncmp(tmp, UNSET, ft_strlen(UNSET) + 1) == 0 || \
		ft_strncmp(tmp, ECHO, ft_strlen(ECHO) + 1) == 0 || \
		ft_strncmp(tmp, EXIT, ft_strlen(EXIT) + 1) == 0 || \
		ft_strncmp(tmp, PWD, ft_strlen(PWD) + 1) == 0 || \
		ft_strncmp(tmp, ENV, ft_strlen(ENV) + 1) == 0 || \
		ft_strncmp(tmp, CD, ft_strlen(CD) + 1) == 0 || \
		ft_strncmp(tmp, EDIT, ft_strlen(EDIT)) == 0)
		flag = BUILT_IN_FLAG;
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
