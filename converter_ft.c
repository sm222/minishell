/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:32:30 by anboisve          #+#    #+#             */
/*   Updated: 2024/04/26 08:20:42 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include "parsing/parsing.h"

static int	find_tok(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		ft_set_mode(s[i]);
		if (s[i] == '|' && ft_set_mode(0) == 0)
			return (0);
		if (ft_isprint(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static short	look_at_pipe(char *s, size_t i)
{
	if (find_tok(s) == 0)
		return (1);
	if (s[i] && s[i + 1])
	{
		if (s[i] == '|' && s[i + 1] == '|')
		{
			if (find_tok(s + i + 2) == 0)
			{
				return (1);
			}
		}
		else
			return (0);
	}
	return (0);
}

static int	bad_con(char *s, short *type)
{
	size_t	i;
	char	err;

	i = 0;
	if (try_end(s, &err))
		return (bad_con_err(type, -1, 258, err));
	ft_set_mode(-1);
	while (s && i < ft_strlen(s))
	{
		while (s && s[i] && ft_set_mode(0) != 0)
			ft_set_mode(s[i++]);
		if ((s[i] == '<' && s[i + 1] == '>') || \
		((s[i] == '>' && s[i + 1] == '<')))
			return (bad_con_err(type, -1, 258, s[i]));
		if (ft_set_mode(s[i]) == 0 && (s[i] == '&' || s[i] == '|'))
		{
			if ((s[i + 1] == '\0') || (s[i] == '&' && s[i + 1] != '&') || \
				(s[i] == '|' && s[i + 1] == '&') || find_end(s, i - 1) || \
				find_tok(s) == 0 || look_at_pipe(s, i))
				return (bad_con_err(type, -1, 258, s[i]));
			i++;
		}
		i++;
	}
	return (SUCCESS);
}

short	find_end(char *s, size_t start)
{
	size_t	i;

	i = start + 2;
	if (s && (s[i - 1] == '\'' || s[i - 1] == '"'))
		return (0);
	while (s && s[i] && ft_isspace(s[i]))
		ft_set_mode(s[i++]);
	if (ft_strlen(s) > i && ft_set_mode(s[i]) == 0)
	{
		while (s[i] == '|' || s[i] == '&')
			i++;
		while (s && s[i] && ft_isspace(s[i]))
			ft_set_mode(s[i++]);
		if (!s[i])
			return (1);
	}
	return (0);
}

size_t	look_for_type(char *s, short *type)
{
	size_t	i;

	i = 0;
	*type = 0;
	bad_con(s, type);
	if (*type == -1)
		return (FAIL);
	ft_set_mode(-1);
	while (s && i < ft_strlen(s) && ft_set_mode(s[i]) != 1000)
	{
		while (s[i] && ft_set_mode(0) != 0)
			ft_set_mode(s[++i]);
		if (s[i] && s[i] == ';')
			break ;
		if (s[i] && s[i + 1])
		{
			if ((s[i] == '&' && s[i + 1] == '&' && s[i + 2]) || \
				(s[i] == '|' && s[i + 1] == '|' && s[i + 2]))
				break ;
		}
		i++;
	}
	if (i < ft_strlen(s))
		*type = s[i];
	return (i);
}

//ls || '|'
//ls 'ads ||'

//ls||'|'

//echo "<>|" | echo "|<>"

//echo '"<''>|" | echo "|<''>"'