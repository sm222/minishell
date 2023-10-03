#include "parsing.h"

int	ft_check_here_doc(char *src, t_rdct *fd)
{
	int	i;
	int	fd_doc;

	fd_doc = 0;
	i = FIRST_INDEX;
	while (src && src[i])
	{
		if (src[i] == '<' && src[i + 1] == '<')
		{
			if (!ft_strchr("<>|", src[i + 2]))
				if (ft_is_not_in_quotes(src, i))
					fd_doc = ft_here_doc(src, i, fd);
		}
		i++;
	}
	return (CORRECT);
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

int	ft_here_doc(char *src, int start, t_rdct *fd)
{
	char	*file;

	if (fd)
		fd->last_doc = ft_is_last_in(src, start);
	file = ft_file_extract(src, start);
	free(file);
	return (CORRECT);
}
