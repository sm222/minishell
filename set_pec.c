/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:51:56 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/23 15:44:16 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	set_pec_to(int val)
{
	int		*pec;

	pec = ft_return_ptr(NULL, PEC);
	*pec = val;
}

int	bad_con_err(short *to_set, short val, int err, char c)
{
	*to_set = val;
	set_pec_to(err);
	ft_printf(2, "%o"MS_NAME"\b: "SENUT" `%c\'\n", NULL, c);
	return (FAIL);
}

static short	check_bett(char *s, char *err, size_t *i)
{
	size_t	j;

	*err = 0;
	j = *i;
	*i += 1;
	while (j--)
	{
		while (j && (s[j] == ' ' || s[j] == '\t'))
			j--;
		if (s[j] == '|' || s[j] == '&')
		{
			*err = s[j];
			return (1);
		}
		if (ft_isprint(s[j]))
		{
			return (0);
		}
	}
	return (0);
}

static short end(char *s, char *err, size_t len)
{
	len--;
	while (s[len] == ' ' || s[len] == '\t')
		len--;
	if (s[len] == '|' || s[len] == '&')
	{
		*err = s[len];
		return (1);
	}
	return (0);
}

short	try_end(char *s, char *err)
{
	size_t	i;
	size_t	j;

	ft_set_mode(-1);
	*err = 0;
	i = ft_strlen(s);
	if (i == 0)
		return (0);
	j = 0;
	while (j < i)
	{
		ft_set_mode(s[j]);
		while (ft_set_mode(s[j]) != 0)
			ft_set_mode(s[++j]);
		if (s[j] == '|' || s[j] == '&')
			if (check_bett(s, err, &j))
				return (1);
		j++;
	}
	if (end(s, err, i))
		return (1);
	return (0);
}

/*
if ((s[i + 1] == '\0') || (s[i] == '&' && s[i + 1] != '&') || \
				(s[i] == '|' && s[i + 1] == '&') || find_end(s, i - 1) || \
				find_tok(s) == 0 || look_at_pipe(s, i))
			{
				return (bad_con_err(type, -1, 258, s[i]));
			}
*/