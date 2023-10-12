#include "parsing.h"

t_loc	*ft_validate_cmds(t_loc *list)
{
	t_loc	*current;

	current = list;
	while (current)
	{
		if (current->tokens->redi_in == INVALID || \
			current->tokens->redi_out == INVALID)
		{
			ft_clear_array(current->decon_cmd);
			current->decon_cmd = NULL;
		}
		current = current->next;
	}
	return (list);
}
