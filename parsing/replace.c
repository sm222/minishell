#include "parsing.h"

int	ft_has_pipe(char *src)
{
	int	i;

	i = -1;
	if (src)
	{
		while (src[++i])
			if (src[i] == '|')
				return (CORRECT);
	}
	return (INCORRECT);
}

int	ft_invalid_pipe(char *cmd)
{
	int	i;

	i = FIRST_INDEX;
	while (cmd[i])
	{
		if (cmd[i] == '|' && cmd[i + 1] == '|')
		{
			ft_check_here_doc(cmd);
			printf("printf: do here_doc here\n");
			ft_putendl_fd("token error near '|'\n", 2);
			return (CORRECT);
		}
		i++;
	}
	return (INCORRECT);
}

void	ft_pipe_op(char *cmd, t_loc *list)
{
	t_idx	index;
	char	*sliced_cmd;
	t_token	*tokens;
	char	**decon;

	tokens = NULL;
	index.start_index = FIRST_INDEX;
	if (ft_invalid_pipe(cmd))
		return ;
	while (ft_has_pipe(cmd))
	{
		index.end_index = ft_at_index(cmd, '|');
		sliced_cmd = ft_strslice(cmd, index.start_index, index.end_index);
		decon = ft_cmd_deconstruct(sliced_cmd, tokens);
		cmd[index.end_index] = PASSED_THROUGH;
		index.start_index = index.end_index;
		ft_add_loc(&list, decon, tokens);
		ft_free(sliced_cmd);
	}
	index.end_index = (int)ft_strlen(cmd);
	sliced_cmd = ft_strslice(cmd, index.start_index, index.end_index);
	decon = ft_cmd_deconstruct(sliced_cmd, tokens);
	ft_add_loc(&list, decon, tokens);
	ft_free(sliced_cmd);
}

char	**ft_cmd_fragments(char *cmd)
{
	int		i;
	char	**res;
	char	*current;
	t_idx	index;

	res = NULL;
	i = FIRST_INDEX;
	while (cmd[i])
	{
		while (cmd[i] == PASSED_THROUGH || cmd[i] == ' ')
			i++;
		index.start_index = i;
		while (cmd[i] != PASSED_THROUGH && cmd[i] > CHAR_LIMIT)
			i++;
		index.end_index = i;
		current = ft_strslice(cmd, index.start_index, index.end_index);
		printf("fief %s\n", current);
		res = ft_arrayjoin(res, current);
		free(current);
	}
	return (res);
}

char	**ft_cmd_deconstruct(char *cmd, t_token *tokens)
{
	t_idx	index;
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
		ft_arrayjoin(quotes, current);
		ft_free(current);
	}
	res = ft_cmd_fragments(cmd);
	index.current_start = 0;
	while (quotes && quotes[index.current_start])
		ft_arrayjoin(res, quotes[index.current_start++]);
	ft_clear_array(quotes);
	return (res);
}
