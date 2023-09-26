#include "parsing.h"

void	ft_add_loc(t_loc **list, char **cmd, t_token *tokens)
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
	current->decon_cmd = cmd;
	current->tokens = tokens;
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
	if (!src)
		return (NULL);
	if (ft_verify(src))
		return (NULL);
	ft_pipe_op(src, &list);
	return (list);
}
