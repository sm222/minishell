/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:31:43 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/26 10:30:40 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_tiny_split(char *s, size_t *cut)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			break ;
	new = ft_calloc(1 + i, sizeof(char));
	if (!new)
		return (new = ft_free(new));
	*cut = i;
	while (i--)
		new[i] = s[i];
	return (new);
}

static char	ft_find(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ('\n');
		i++;
	}
	return ('0');
}

/*
return line from fd
*/
char	*get_next_line(int fd)
{
	static char	*book[INT_MAX / 2];
	t_info		t_val;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > INT_MAX / 2)
		return (NULL);
	if (!book[fd])
		book[fd] = ft_calloc(1, sizeof(char));
	t_val.tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	t_val.rv = 0;
	while (ft_find(book[fd]) == '0')
	{
		ft_bzero(t_val.tmp, BUFFER_SIZE + 1);
		t_val.rv = read(fd, t_val.tmp, BUFFER_SIZE);
		if (t_val.rv <= 0)
			break ;
		book[fd] = ft_strfjoin(book[fd], t_val.tmp);
	}
	t_val.tmp = ft_free(t_val.tmp);
	if (t_val.rv == -1 || (t_val.rv <= 0 && *book[fd] == 0))
		return (book[fd] = ft_free(book[fd]), NULL);
	t_val.tmp = ft_tiny_split(book[fd], &t_val.cut);
	t_val.tmp2 = book[fd];
	book[fd] = ft_strfjoin(NULL, book[fd] + t_val.cut);
	return (ft_free(t_val.tmp2), t_val.tmp);
}
