
#include "token.h"

t_token	*make_token(char build_in, int mode, int redi_in, int redi_out)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->mode = mode;
	new->pipe_in = 0;
	new->pipe_out = 0;
	new->build_in = build_in;
	new->redi_in = redi_in;
	new->redi_out = redi_out;
	return (new);
}
