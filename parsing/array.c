#include "parsing.h"

int	ft_arraylen(char **src)
{
	int	i;

	i = 0;
	if (src)
		while (src[i])
			i++;
	return (i);
}

void	*ft_clear_array(char **src)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			src[i] = ft_free(src[i]);
			i++;
		}
		src = ft_free(src);
	}
	return (NULL);
}

char	**ft_arrayjoin(char **src, char *s)
{
	char	**res;
	int		i;
	int		len;

	len = ft_arraylen(src);
	res = ft_calloc(len + 2, sizeof(char *));
	i = 0;
	if (!s)
		return (src);
	if (src)
	{
		while (src[i])
		{
			res[i] = ft_strdup(src[i]);
			i++;
		}
	}
	res[i] = ft_strdup(s);
	ft_clear_array(src);
	return (res);
}
