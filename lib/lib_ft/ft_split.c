/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:09:23 by anboisve          #+#    #+#             */
/*   Updated: 2023/04/02 17:26:47 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_allfree(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

static int	nb_word(const char *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

char	*ft_strdup_c(const char *str, char c)
{
	size_t	i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	new = ft_calloc(i + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (i--)
		new[i] = str[i];
	return (new);
}

/*
take str and char to split on, return a double array
*/
char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	new = (char **)ft_calloc(nb_word(s, c) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (nb_word(s + i, c))
	{
		while (s[i] && s[i] == c)
			i++;
		new[index] = ft_strdup_c(s + i, c);
		if (!new[index++])
			return (ft_allfree(new), NULL);
		while (s[i] && s[i] != c)
			i++;
	}
	return (new);
}
