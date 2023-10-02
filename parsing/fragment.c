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

char	**ft_cmd_fragments(char *cmd)
{
	t_idx	idx;
	char	**res;
	char	*current;

	res = NULL;
	ft_bzero(&idx, sizeof(t_idx));
	while (cmd[idx.current])
	{
		printf("radar\n");
		while (cmd[idx.current] && (cmd[idx.current] == ' ' || \
				cmd[idx.current] == PASSED_THROUGH))
			idx.current++;
		ft_word_delimiter(cmd, &idx);
		current = ft_strslice(cmd, idx.start_index, idx.end_index);
		res = ft_arrayjoin(res, current);
		free(current);
	}
	return (res);
}

char	**ft_cmd_deconstruct(char *cmd, t_token *tokens)
{
	char	**res;

	res = NULL;
	tokens = NULL;
	if (!cmd)
		return (res);
	if (ft_redirect_op(cmd, tokens) == CORRECT)
	{
		printf("cmd: %s\n", cmd);
		while (ft_has_quotes(cmd))
			ft_quote_op(cmd);
		res = ft_cmd_fragments(cmd);
		printf("changed cmd: %s\n", cmd);
	}
	return (res);
}
