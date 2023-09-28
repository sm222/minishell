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

int	ft_check_ignore(char *src, int start, int end)
{
	int	nb;

	nb = 0;
	while (start < end)
		if (src[start++] == IGNORE_QUOTES)
			nb++;
	return (nb);
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
		if (!open_quote && (src[i] == '\'' || src[i] == '"'))
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

void	ft_quote_op(char *cmd)
{
	t_idx	index;

	index = ft_quotes_delimitation(cmd);
	cmd[index.start_index] = IGNORE_QUOTES;
	cmd[index.end_index] = IGNORE_QUOTES;
}
