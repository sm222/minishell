#include "parsing.h"

int	ft_is_not_in_quotes(char *src, char c)
{
	int	i;
	int	open_quote;

	i = 0;
	open_quote = INCORRECT;
	while (src[i] != c)
	{
		if ((src[i] == '\'' || src[i] == '"') && !open_quote)
			open_quote = CORRECT;
		else if ((src[i] == '\'' || src[i] == '"') && open_quote)
			open_quote = INCORRECT;
		i++;
	}
	return (!open_quote);
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

	i = 0;
	open_quote = INCORRECT;
	while (src[i])
	{
		if ((src[i] == '\'' || src[i] == '"') && !open_quote)
		{
			index.start_index = i;
			open_quote = CORRECT;
		}
		else if ((src[i] == '\'' || src[i] == '"') && open_quote)
		{
			index.end_index = i;
			open_quote = INCORRECT;
		}
		i++;
	}
	return (index);
}

char	*ft_quote_op(char *cmd)
{
	char	*res;
	t_idx	index;

	if (!ft_has_quotes(cmd))
		return (NULL);
	index = ft_quotes_delimitation(cmd);
	res = ft_strslice(cmd, index.start_index, index.end_index);
	while (index.start_index < index.end_index)
		cmd[index.start_index++] = PASSED_THROUGH;
	return (res);
}
