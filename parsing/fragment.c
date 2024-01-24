/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:35:50 by brheaume          #+#    #+#             */
/*   Updated: 2024/01/24 18:27:53 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_word_delimiter(char *cmd, t_idx *index)
{
	int	i;

	i = index->current;
	index->start_index = i;
	while (cmd[i] && cmd[i] != PASSED_THROUGH && !ft_isspace(cmd[i]))
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
		while (cmd[idx.current] && (ft_isspace(cmd[idx.current]) || \
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
	if (!cmd)
		return (res);
	while (ft_has_quotes(cmd))
		ft_quote_op(cmd);
	if (ft_redirect_op(cmd, tokens) == CORRECT)
		res = ft_cmd_fragments(cmd);
	return (res);
}
