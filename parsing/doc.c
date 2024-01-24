/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:35:31 by brheaume          #+#    #+#             */
/*   Updated: 2023/11/07 23:25:23 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_check_here_doc(char *src, t_idx *i_doc)
{
	int	i;

	i = FIRST_INDEX;
	while (src && src[i])
	{
		if (src[i] == '<' && src[i + 1] == '<')
		{
			if (!ft_strchr("<>|", src[i + 2]))
			{
				if (ft_is_not_in_quotes(src, i))
				{
					i_doc->start_index = i;
					return (CORRECT);
				}
			}
		}
		i++;
	}
	return (INCORRECT);
}

int	ft_is_last_in(char *src, int start)
{
	if (start + 2 != (int)ft_strlen(src))
		start = start + 2;
	else
		return (CORRECT);
	while (src[start])
	{
		if (src[start] == '<')
			if (ft_is_not_in_quotes(src, start))
				return (INCORRECT);
		start++;
	}
	return (CORRECT);
}

static short	ft_no_quotes(char *src, int start_index)
{
	short	no_quotes;

	no_quotes = CORRECT;
	if (start_index < (int)ft_strlen(src))
		start_index++;
	while (src && src[start_index] && ft_isspace(src[start_index]))
		start_index++;
	while (src && src[start_index] && src[start_index] == '<')
		start_index++;
	while (src && src[start_index] && ft_isspace(src[start_index]))
		start_index++;
	while (src && src[start_index] && !ft_isspace(src[start_index]))
	{
		if (src[start_index] == IGNORE_QUOTES)
			no_quotes = INCORRECT;
		start_index++;
	}
	return (no_quotes);
}

static int	ft_run_here_doc(char *src, t_idx *limit, t_rdct *fd)
{
	char	*file;
	int		fd_doc;
	int		current;
	short	no_quotes;

	limit->current_start = limit->start_index + 1;
	if (ft_isspace(src[limit->current_start + 1]))
		limit->current_start++;
	current = limit->start_index;
	no_quotes = CORRECT;
	if (fd)
		fd->last_doc = ft_is_last_in(src, limit->start_index);
	ft_word_delimiter(src, limit);
	no_quotes = ft_no_quotes(src, limit->end_index);
	file = ft_file_extract(src, limit->current_start);
	while (current < limit->current_start)
		src[current++] = PASSED_THROUGH;
	if (!file)
		return (ft_error_file(file, NO_FILE_IN));
	ft_return_ptr(&file, DOC_FILE);
	fd_doc = make_here_doc(no_quotes, file);
	file = ft_free(file);
	return (fd_doc);
}

int	ft_here_doc(char *src, t_rdct *fd)
{
	t_idx	i;
	int		fd_doc;

	fd_doc = 0;
	ft_bzero(&i, sizeof(t_idx));
	if (ft_check_here_doc(src, &i))
		while (fd_doc != CANCEL && ft_check_here_doc(src, &i))
			fd_doc = ft_run_here_doc(src, &i, fd);
	else
		return (INCORRECT);
	while (src[i.start_index])
		i.start_index++;
	return (fd_doc);
}
