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

void	ft_init_start_cmd(char *cmd, t_loc **list)
{
	t_idx	index;
	t_token	*tokens;
	char	**decon;

	ft_add_node(list);
	index.start_index = FIRST_INDEX;
	tokens = ft_calloc(NODE, sizeof(t_token));
	ft_set_tokens(list, tokens);
	if (ft_has_pipe(cmd))
	{
		index.end_index = ft_at_index(cmd, '|');
		cmd[index.end_index] = PASSED_THROUGH;
	}
	else
		index.end_index = (int)ft_strlen(cmd);
	(*list)->slice = ft_strslice(cmd, index.start_index, index.end_index);
	decon = ft_cmd_deconstruct((*list)->slice, (*list)->tokens);
	ft_set_decon(list, decon);
	ft_free((*list)->slice);
}

void	ft_pipe_op(char *cmd, t_loc **list)
{
	while (ft_has_pipe(cmd))
		ft_init_start_cmd(cmd, list);
	ft_init_start_cmd(cmd, list);
}
