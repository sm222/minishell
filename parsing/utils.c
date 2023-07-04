#include "parsing.h"

int	ft_at_index(char *src, char c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
