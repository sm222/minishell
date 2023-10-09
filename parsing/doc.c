#include "parsing.h"

int	ft_check_here_doc(char *src, t_idx *i_doc)
{
	int			i;

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
	while (src[start])
	{
		if (src[start] == '<')
			if (ft_is_not_in_quotes(src, start))
				return (INCORRECT);
		start++;
	}
	return (CORRECT);
}

int	ft_run_here_doc(char *src, t_idx limit, t_rdct *fd)
{
	char	*file;
	int		fd_doc;
	int		has_quotes;

	limit.start_index++;
	limit.current_start = limit.start_index;
	if (fd)
		fd->last_doc = ft_is_last_in(src, limit.start_index);
	ft_word_delimiter(src, &limit);
	while (limit.start_index < limit.end_index)
	{
		if (src[limit.start_index] == '\'' || src[limit.start_index] == '"')
		{
			src[limit.start_index] = IGNORE_QUOTES;
			has_quotes = CORRECT;
		}
		limit.start_index++;
	}
	file = ft_file_extract(src, limit.current_start);
	while (limit.current_start < limit.end_index)
		src[limit.current_start++] = PASSED_THROUGH;
	fd_doc = make_here_doc(has_quotes, file);
	return (fd_doc);
}

int	ft_here_doc(char *src, t_rdct *fd)
{
	t_idx	i;
	int		fd_doc;

	ft_bzero(&i, sizeof(t_idx));
	if (ft_check_here_doc(src, &i))
		fd_doc = ft_run_here_doc(src, i, fd);
	else
		return (INCORRECT);
	while (src[i.start_index])
		i.start_index++;
	return (fd_doc);
}
