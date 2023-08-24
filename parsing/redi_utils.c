#include "parsing.h"

int	ft_redirect_index(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '<' || src[i] == '>')
			return (i);
		i++;
	}
	return (INVALID);
}

int	ft_redirect_rev_index(char *src)
{
	int	i;

	i = (int)ft_strlen(src);
	while (i)
	{
		if (src[i] == '<' || src[i] == '>')
			return (i);
		i--;
	}
	return (INVALID);
}
