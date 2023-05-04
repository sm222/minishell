/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:20:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/04/13 10:30:19 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	give_index(char **list, char in)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		if (list[i][0] && in == list[i][0] && ft_strlen(list[i]) > 1)
			return (list[i][1]);
		i++;
	}
	return (0);
}

static int	catch_type(const char c, char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		if (list[i][0] == c)
			return (ft_strlen(list[i]));
		i++;
	}
	return (0);
}

static char	**return_double(t_list *lst, int mode)
{
	char	**tmp;
	t_list	*keep;
	t_list	*next_node;
	size_t	i;

	i = 0;
	tmp = NULL;
	if (mode)
		tmp = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	keep = lst;
	while (keep)
	{
		if (mode)
			tmp[i++] = keep->content;
		next_node = keep->next;
		free(keep);
		keep = next_node;
	}
	tmp[i] = NULL;
	return (tmp);
}

static int	return_index(char *s, char **list, t_index *index)
{
	char	mem;

	while (s[index->i] && catch_type(s[index->i], list) == 1)
		index->i++;
	if (s[index->i] && catch_type(s[(index->i)], list) == 2)
	{
		mem = give_index(list, s[index->i++ + index->j++]);
		if (s[index->i] && s[index->i] == mem)
		{
			index->i++;
			return (2);
		}
		while (s[index->i + index->j] && s[index->i + index->j] != mem)
			index->j++;
		return (1);
	}
	else
	{
		while (catch_type(s[index->i + index->j], list) != 1 && \
		ft_strlen(s) >= index->i + index->j)
			index->j++;
	}
	return (0);
}

char	**ft_str_split(const char *s, char **list)
{
	t_list	*data;
	t_index	index;
	char	*tmp;

	data = NULL;
	ft_bzero(&index, sizeof(t_index));
	while (s[index.i])
	{
		index.j = 0;
		index.l = return_index((char *)s, list, &index);
		if (!s[index.i] || !s[index.i + index.j])
			break ;
		if (index.l == 2)
			continue ;
		index.k++;
		tmp = ft_substr(s, index.i, index.j);
		ft_lstadd_back(&data, ft_lstnew(tmp));
		if (index.k != (size_t)ft_lstsize(data) || !tmp)
			return (return_double(data, 0));
		if (ft_strlen(tmp))
			index.i += ft_strlen(tmp);
		if (index.l)
			index.i++;
	}
	return (return_double(data, 1));
}
