#include "export.h"

char	**change_arg_env(char **en, int i, char *new)
{
	char	*tmp;

	tmp = ft_strdup(new);
	if (tmp)
	{
		ft_free(en[i]);
		en[i] = tmp;
	}
	return (en);
}