# include "execution.h"

int	find_path(char *name, char **out)
{
	char	*tmp;

	tmp = NULL;
	out = NULL;
	if (access(name, X_OK | F_OK) == 0)
	{
		*out = ft_strdup(name);
	}
	
	return (1);
}