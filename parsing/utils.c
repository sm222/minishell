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
		{
			if (src[start] == IGNORE_QUOTES)
				start++;
			else if (src[start] == PASSED_QUOTES)
			{
				res[i++] = ' ';
				start++;
			}
			else if (src[start] == PASSED_SINGLE)
			{
				res[i++] = '\'';
				start++;
			}
			else if (src[start] == PASSED_DOUBLE)
			{
				res[i++] = '"';
				start++;
			}
			else
				res[i++] = src[start++];
		}
		return (res);
	}
	return (NULL);
}

void	ft_purge(t_loc *list)
{
	t_loc	*current;
	t_loc	*temp;

	current = list;
	while (current)
	{
		if (current->tokens)
			ft_free(current->tokens);
		if (current->decon_cmd)
			ft_clear_array(current->decon_cmd);
		temp = current;
		current = current->next;
		ft_free(temp);
	}
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
