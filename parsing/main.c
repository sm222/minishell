#include "parsing.h"

void	ft_set_tokens(t_loc **list, t_token *tokens)
{
	t_loc	*current;

	current = *list;
	while (current->next)
		current = current->next;
	current->tokens = tokens;
}

void	ft_set_decon(t_loc **list, char **decon_cmd)
{
	t_loc	*current;

	current = *list;
	while (current->next)
		current = current->next;
	current->decon_cmd = decon_cmd;
}

void	ft_add_node(t_loc **list)
{
	t_loc	*current;
	t_loc	*last;

	last = *list;
	current = ft_calloc(NODE, sizeof(t_loc));
	if (!current)
	{
		ft_putendl_fd("error malloc\n", 2);
		return ;
	}
	current->next = NULL;
	if (*list == NULL)
		*list = current;
	else
	{
		while (last->next)
			last = last->next;
		last->next = current;
	}
}

t_loc	*ft_parsing(char *src)
{
	t_loc	*list;

	list = NULL;
	ft_return_ptr(&list, PARSE);
	if (!src)
		return (NULL);
	if (!ft_verify(src))
		return (NULL);
	ft_pipe_op(src, &list);
	return (ft_validate_cmds(list));
}
