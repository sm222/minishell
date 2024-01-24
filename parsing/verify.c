/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:37:07 by brheaume          #+#    #+#             */
/*   Updated: 2024/01/24 18:28:34 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_quote_error(char *src)
{
	int		i;
	char	c;
	int		open_mark;

	i = FIRST_INDEX;
	open_mark = INCORRECT;
	if (!src)
		return (INCORRECT);
	while (i < (int)ft_strlen(src))
	{
		if (src[i] == '"' || src[i] == '\'')
		{
			c = src[i++];
			open_mark = CORRECT;
			while (src[i] && src[i] != c)
				i++;
			if (i != (int)ft_strlen(src))
				open_mark = INCORRECT;
		}
		i++;
	}
	if (open_mark)
		return (CORRECT);
	return (INCORRECT);
}

static int	ft_redirect_error(char *src)
{
	int		i;
	char	current_redirect;

	i = 0;
	while (src[i])
	{
		if (src[i] == '<' || src[i] == '>')
		{
			current_redirect = src[i];
			if (i + 1 < (int)ft_strlen(src))
				if (src[i + 1] != current_redirect && !ft_isprint(src[i]))
					return (CORRECT);
			if (i + 2 < (int)ft_strlen(src))
				if (src[i + 2] == '<' || src[i + 2] == '>')
					return (CORRECT);
		}
		i++;
	}
	return (INCORRECT);
}

int	ft_pipe_error(char *src)
{
	int	i;

	i = ft_at_index(src, '|');
	if (i == INVALID)
		return (INCORRECT);
	i--;
	while (i)
	{
		if (!ft_isspace(src[i]))
			return (INCORRECT);
		i--;
	}
	if (ft_isspace(src[i]))
		return (CORRECT);
	else
		return (INCORRECT);
}

int	ft_verify(char *src)
{
	int	res;

	res = CORRECT;
	if (ft_quote_error(src))
	{
		ft_putendl_fd(MS_NAME"\b: token error near quote", 2);
		res = INCORRECT;
	}
	if (ft_redirect_error(src))
	{
		ft_putendl_fd(MS_NAME"\b: token error near redirection", 2);
		res = INCORRECT;
	}
	if (ft_pipe_error(src))
	{
		ft_putendl_fd(MS_NAME"\b: syntax error near unexpected token '|'", 2);
		res = INCORRECT;
	}
	if (res == INCORRECT)
	{
		ft_here_doc(src, NULL);
		ft_set_error_code(258);
	}
	return (res);
}
