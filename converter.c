#include "include/minishell.h"

short	converter(const char *in, t_cmd **list)
{
	t_loc	*head;

	if (!in || !list)
		return (BAD_ARGS);
}