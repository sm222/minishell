
#include "token.h"

t_token	*make_token(int in, int out, char build_in)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->pipe_in = in;
	new->pipe_out = out;
	new->build_in = build_in;
	return (new);
}