
#include "token.h"


t_token	*make_token(int in, int out, char build_in, int mode)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->mode = mode;
	new->pipe_in = in;
	new->pipe_out = out;
	new->build_in = build_in;
	new->redi_in = -1;
	new->redi_out = -1;
	return (new);
}
