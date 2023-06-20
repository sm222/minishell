
#include "token.h"

t_token	*make_token(int flag, int redi_in, int redi_out)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->redi_in = redi_in;
	new->redi_out = redi_out;
	new->mode = flag;
	return (new);
}
