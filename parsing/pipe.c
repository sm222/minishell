#include "parsing.h"

int	ft_has_pipe(char *src)
{
	int	i;

	i = -1;
	if (src)
	{
		while (src[++i])
			if (src[i] == '|')
				if (ft_is_not_in_quotes(src, i))
					return (CORRECT);
	}
	return (INCORRECT);
}

void	ft_pipe_op(char *cmd, t_loc **list)
{
	t_idx	index;
	char	*sliced_cmd;
	t_token	*tokens;
	char	**decon;

	tokens = NULL;
	index.start_index = FIRST_INDEX;
	while (ft_has_pipe(cmd))
	{
		index.end_index = ft_at_index(cmd, '|');
		sliced_cmd = ft_strslice(cmd, index.start_index, index.end_index);
		decon = ft_cmd_deconstruct(sliced_cmd, tokens);
		cmd[index.end_index] = PASSED_THROUGH;
		index.start_index = index.end_index;
		ft_add_loc(list, decon, tokens);
		ft_free(sliced_cmd);
	}
	index.end_index = (int)ft_strlen(cmd);
	sliced_cmd = ft_strslice(cmd, index.start_index, index.end_index);
	decon = ft_cmd_deconstruct(sliced_cmd, tokens);
	ft_add_loc(list, decon, tokens);
	ft_free(sliced_cmd);
}
