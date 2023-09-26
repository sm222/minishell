#include "parsing.h"

void	ft_word_delimiter(char *cmd, t_idx *index)
{
	int	i;

	i = index->current;
	index->start_index = i;
	while (cmd[i] && cmd[i] != PASSED_THROUGH && cmd[i] != ' ')
		i++;
	index->end_index = i;
	index->current = i;
}

char	**ft_cmd_fragments(char *cmd, char **quotes)
{
	t_idx	idx;
	char	**res;
	char	*current;

	res = NULL;
	ft_bzero(&idx, sizeof(t_idx));
	while (cmd[idx.current])
	{
		while (cmd[idx.current] && (cmd[idx.current] == PASSED_THROUGH \
				|| cmd[idx.current] == ' '))
			idx.current++;
		if (cmd[idx.current] == PASSED_QUOTES)
			res = ft_add_quotes(res, quotes, cmd, &idx);
		ft_word_delimiter(cmd, &idx);
		current = ft_strslice(cmd, idx.start_index, idx.end_index);
		res = ft_arrayjoin(res, current);
		free(current);
	}
	return (res);
}

char	**ft_array_invert(char **res)
{
	int		i;
	int		j;
	char	*temp;

	i = FIRST_INDEX;
	j = ft_arraylen(res) - 1;
	while (i < (ft_arraylen(res) / 2))
	{
		temp = res[i];
		res[i] = res[j];
		res[j] = temp;
		i++;
		j--;
	}
	return (res);
}

char	**ft_cmd_deconstruct(char *cmd, t_token *tokens)
{
	char	*current;
	char	**quotes;
	char	**res;

	res = NULL;
	quotes = NULL;
	if (!cmd)
		return (res);
	tokens = ft_redirect_op(cmd);
	while (ft_has_quotes(cmd))
	{
		current = ft_quote_op(cmd);
		quotes = ft_arrayjoin(quotes, current);
		ft_free(current);
	}
	if (quotes)
		quotes = ft_array_invert(quotes);
	res = ft_cmd_fragments(cmd, quotes);
	ft_clear_array(quotes);
	return (res);
}
