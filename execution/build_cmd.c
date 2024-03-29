/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:25 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:24:26 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

/// @brief	make a node of command
/// @param	cmd	command in double array
/// @param	tok	token
/// @return	new cmd node
t_cmd	*cmd_make_node(char **cmd, t_token *tok)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	if (!new)
	{
		new = ft_free(new);
		return (NULL);
	}
	new->command = ft_cpy_double_char(cmd);
	if (!new->command && cmd)
	{
		ft_free(new);
		ft_free(tok);
		return (NULL);
	}
	new->tok = tok;
	return (new);
}

/// @brief	get len of the list
/// @param	list	input
/// @return	len of the list
size_t	cmd_node_len(t_cmd *list)
{
	size_t	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

/// @brief	add a node at the end of the list
/// @test	if you want to send a fail file in a cmd send 
/// @test	cmd_make_node_last(t_cmd **list, NULL, t_token *tok) 
/// @param	list	t_cmd** list input
/// @param	cmd		argument, need to be malloc
/// @param	tok		type of action
/// @return	return negatif nuber if fail, else return the size of the list
/// @return	envent if fail (bad args it will free cmd)
short	cmd_make_node_last(t_cmd **list, char **cmd, t_token *tok)
{
	t_cmd	*tmp;

	if (!list)
	{
		ft_double_sfree((void **)cmd);
		return (BAD_ARGS);
	}
	tmp = (*list);
	if (!tmp)
	{
		*list = cmd_make_node(cmd, tok);
		ft_double_sfree((void **)cmd);
		if (!*list)
			return (M_FAIL);
		return (1);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = cmd_make_node(cmd, tok);
	ft_double_sfree((void **)cmd);
	if (!tmp->next)
		return (M_FAIL);
	tmp->next->prev = tmp;
	return (cmd_node_len(*list));
}

/// @brief	free the list
/// @param	in	t_cmd** input
void	cmd_free(t_cmd **in)
{
	t_cmd	*ptr;
	t_cmd	*tmp;

	ptr = (*in);
	while (ptr)
	{
		tmp = ptr->next;
		ptr->command = (char **)ft_double_sfree((void **)ptr->command);
		if (ptr && ptr->tok)
		{
			close_fd(ptr->tok->redi_in);
			close_fd(ptr->tok->redi_out);
		}
		ptr->tok = ft_free(ptr->tok);
		ft_free(ptr);
		ptr = tmp;
	}
	(*in) = NULL;
}
