/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_dolar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:06:44 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/24 18:12:54 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief add for here_doc
/// @param s 
/// @param i 
/// @param en 
/// @return 
static char	*make_edit_str(char *s, size_t *i, char **en)
{
	char	*s1;
	char	*s2;
	char	*new;
	size_t	j;

	if (ft_find_doc(s, *i))
	{
		new = ft_strdup(s);
		ft_free(s);
		return (new);
	}
	ft_set_mode(s[*i + 1]);
	j = *i + 1;
	s1 = ft_strndup(s, *i);
	if (s[j] && ft_isalpha(s[j]))
		ft_set_mode(s[j++]);
	while (s[j] && (ft_isalnum(s[j]) || ft_strchr(DOLAR_LIST, s[j])))
		ft_set_mode(s[j++]);
	s2 = ft_strdup(s + j);
	ft_printf(NO_PRINT, "%o%s%s%s", &new, s1, get_env(en, s + *i + 1), s2);
	ft_free(s);
	ft_free(s1);
	ft_free(s2);
	*i -= 1;
	return (new);
}

static char	*pros_or_dolar(char *s, size_t i, char c, int err)
{
	char	*s1;
	char	*s2;
	char	*new;
	size_t	j;

	j = i + 1;
	s1 = ft_strndup(s, i);
	j++;
	s2 = ft_strdup(s + j);
	if (c == '?')
		ft_printf(NO_PRINT, "%o%S%d%S", &new, s1, err, s2);
	if (c == '$')
		ft_printf(NO_PRINT, "%o%S%c%S", &new, s1, '$', s2);
	ft_free(s);
	return (new);
}

static short	skip_2(char *in)
{
	if (ft_strlen(in) >= 1)
	{
		if (in[0] == '$' && ft_isspace(in[1]))
			return (1);
		if (in[0] == '$' && in[1] == '\0')
			return (1);
	}
	return (0);
}

static short	look_for_those(char *in, char c1, char c2)
{
	if (ft_strlen(in) >= 2)
	{
		if (in[0] == '$' && in[1] == c1)
			return (1);
		if (in[0] == '$' && in[1] == c2)
			return (1);
	}
	return (0);
}

void	ft_change_dolar(char **old, char **en, short here_doc, int err)
{
	char	*new;
	t_index	index;

	if (!old || !*old)
		return ;
	ft_bzero(&index, sizeof(t_index));
	new = *old;
	index.j = ft_strlen(new);
	ft_set_mode(-1);
	while (index.j > index.i)
	{
		if (ft_set_mode(new[index.i]) != 1 || here_doc)
		{
			if (skip_2(new + index.i))
				index.i++;
			if (look_for_those(new + index.i, '?', '$'))
				new = pros_or_dolar(new, index.i, new[index.i + 1], err);
			else if (new[index.i] == '$')
				new = make_edit_str(new, &index.i, en);
		}
		index.i++;
		index.j = ft_strlen(new);
	}
	*old = new;
}
