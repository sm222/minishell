#include "execution.h"

t_cmd	*cmd_make_node(char **cmd, int order)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->command = ft_cpy_double_char(cmd);
	new->order = order;
	return (new);
}

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

/// @brief add a node at the end of the list
/// @param list list input
/// @param cmd argument
/// @param order of execution
/// @return return negatif nuber if fail, else return the size of the list
short	cmd_make_node_last(t_cmd **list, char **cmd, int order)
{
	t_cmd	*tmp;
	size_t	len;

	if (!list)
		return (BAD_ARGS);
	tmp = (*list);
	if (!tmp)
	{
		*list = cmd_make_node(cmd, order);
		if (!*list)
			return (M_FAIL);
		(*list)->order = 1;
		return (1);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = cmd_make_node(cmd, order);
	if (!tmp->next)
		return (M_FAIL);
	tmp->next->prev = tmp;
	len = cmd_node_len(*list);
	tmp->next->order = len + 1;
	return (len);
}

/// @brief free the list
/// @param in input
void	cmd_free(t_cmd *in)
{
	t_cmd	*tmp;

	while (in)
	{
		ft_double_sfree((void **)in->command);
		tmp = in->next;
		ft_free(in);
		in = tmp;
	}
}
