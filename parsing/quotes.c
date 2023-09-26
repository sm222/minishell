#include "parsing.h"

int	ft_is_not_in_quotes(char *src, int index)
{
	int	i;
	int	not_in_quote;

	i = 0;
	not_in_quote = CORRECT;
	while (src[i] && i < index)
	{
		if ((src[i] == '\'' || src[i] == '"') && not_in_quote)
			not_in_quote = INCORRECT;
		else if ((src[i] == '\'' || src[i] == '"') && !not_in_quote)
			not_in_quote = CORRECT;
		i++;
	}
	return (not_in_quote);
}

int	ft_has_quotes(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '\'' || src[i] == '"')
			return (CORRECT);
		i++;
	}
	return (INCORRECT);
}

t_idx	ft_quotes_delimitation(char *src)
{
	int		i;
	t_idx	index;
	int		open_quote;
	char	current_quote;

	i = 0;
	open_quote = INCORRECT;
	ft_bzero(&index, sizeof(t_idx));
	while (src[i])
	{
		if ((src[i] == '\'' || src[i] == '"') && !open_quote)
		{
			index.start_index = i;
			open_quote = CORRECT;
			current_quote = src[i];
		}
		else if (open_quote && src[i] == current_quote)
		{
			index.end_index = i;
			open_quote = INCORRECT;
		}
		i++;
	}
	return (index);
}

char	**ft_add_quotes(char **res, char **quotes, char *cmd, t_idx *index)
{
	int	current;
	int	current_quote;

	current = index->current;
	current_quote = index->current_quote;
	while (cmd[current] && cmd[current] == PASSED_QUOTES)
		current++;
	if (quotes)
	{
		if (quotes[current_quote])
		{
			res = ft_arrayjoin(res, quotes[current_quote]);
			current_quote++;
		}
	}
	index->current = current;
	index->current_quote = current_quote;
	return (res);
}

char	*ft_quote_op(char *cmd)
{
	char	*res;
	t_idx	index;

	if (!ft_has_quotes(cmd))
		return (NULL);
	index = ft_quotes_delimitation(cmd);
	if (index.start_index + 1 == index.end_index)
		res = ft_strdup("\0");
	else
		res = ft_strslice(cmd, index.start_index + 1, index.end_index);
	while (index.start_index <= index.end_index)
		cmd[index.start_index++] = PASSED_QUOTES;
	return (res);
}
