#include "parsing.h"

int	ft_set_error_code(int code)
{
	int	*pec;

	pec = ft_return_ptr(NULL, PEC);
	*pec = code;
	return (code);
}

t_loc	*ft_validate_cmds(t_loc *list)
{
	t_loc	*current;

	current = list;
	while (current)
	{
		if (current->tokens->redi_doc == CANCEL)
		{
			ft_set_error_code(1);
			ft_purge(list);
			return (NULL);
		}
		if (current->tokens->redi_in == INVALID || \
			current->tokens->redi_out == INVALID)
		{
			ft_set_error_code(1);
			ft_clear_array(current->decon_cmd);
			current->decon_cmd = NULL;
		}
		current = current->next;
	}
	return (list);
}
