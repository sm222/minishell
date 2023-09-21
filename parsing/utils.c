#include "parsing.h"

int	ft_at_index(char *src, char c)
{
	int	i;

	i = FIRST_INDEX;
	if (src)
	{
		while (src[i])
		{
			if (src[i] == c)
				if (ft_is_not_in_quotes(src, i))
					return (i);
			i++;
		}
	}
	return (INVALID);
}

int	ft_at_rev_index(char *src, char c)
{
	int	i;
	int	in_quotes;

	if (src)
	{
		i = ft_strlen(src);
		in_quotes = ft_is_not_in_quotes(src, c);
		if (!in_quotes)
			while (src[--i])
				if (src[i] == c)
					return (i);
	}
	return (INVALID);
}

char	*ft_strslice(char *src, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	if (src && start != end)
	{
		res = ft_calloc(end - start + 1, sizeof(char));
		if (!res)
			return (NULL);
		while (start < end)
			res[i++] = src[start++];
		return (res);
	}
	return (NULL);
}

void	ft_purge(char **decon, char *src)
{
	ft_clear_array(decon);
	ft_free(src);
}

void	ft_pass_through(char **decon)
{
	int	i;

	i = FIRST_INDEX;
	if (decon)
	{
		while (decon[i])
			ft_putendl_fd(decon[i++], 1);
	}
}
