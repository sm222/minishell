
#include "token.h"

t_token	*make_token(int flag, char *redi_in, char *redi_out)
{
	t_token	*new;

	(void)flag;
	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	if (redi_in)
	{
		new->redi_in = ft_strdup(redi_in);
		if (!new->redi_in)
			return (ft_free(new));
	}
	if (redi_out)
	{
		new->redi_out = ft_strdup(redi_out);
		if (!new->redi_out)
		{
			ft_free(new->redi_in);
			ft_free(new);
		return (NULL);
		}
	}
	return (new);
}
