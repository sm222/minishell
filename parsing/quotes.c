/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:36:34 by brheaume          #+#    #+#             */
/*   Updated: 2024/01/24 18:26:04 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_is_not_in_quotes(char *src, int index)
{
	int		i;
	int		not_in_quote;
	char	current_quote;

	i = 0;
	not_in_quote = CORRECT;
	current_quote = 0;
	while (src[i] && i < index)
	{
		if ((src[i] == '\'' || src[i] == '"' || \
				src[i] == IGNORE_QUOTES) && not_in_quote)
		{
			not_in_quote = INCORRECT;
			current_quote = src[i];
		}
		else if (src[i] == current_quote && !not_in_quote)
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
			if (ft_is_not_in_quotes(src, i))
				return (CORRECT);
		i++;
	}
	return (INCORRECT);
}

t_idx	ft_quotes_delimitation(char *src)
{
	t_idx	i;
	int		open_quote;
	char	current_quote;

	open_quote = INCORRECT;
	ft_bzero(&i, sizeof(t_idx));
	while (src[i.current_start])
	{
		if (!open_quote && (src[i.current_start] == '\'' \
			|| src[i.current_start] == '"'))
		{
			i.start_index = i.current_start;
			open_quote = CORRECT;
			current_quote = src[i.current_start];
		}
		else if (open_quote && src[i.current_start] == current_quote)
		{
			i.end_index = i.current_start;
			open_quote = INCORRECT;
			return (i);
		}
		i.current_start++;
	}
	return (i);
}

void	ft_quote_op(char *cmd)
{
	t_idx	index;

	index = ft_quotes_delimitation(cmd);
	cmd[index.start_index] = IGNORE_QUOTES;
	cmd[index.end_index] = IGNORE_QUOTES;
	index.current_start = index.start_index;
	while (index.current_start < index.end_index)
	{
		if (ft_isspace(cmd[index.current_start]))
			cmd[index.current_start] = PASSED_QUOTES;
		if (cmd[index.current_start] == '\'')
			cmd[index.current_start] = PASSED_SINGLE;
		if (cmd[index.current_start] == '"')
			cmd[index.current_start] = PASSED_DOUBLE;
		index.current_start++;
	}
}
