/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:35:24 by brheaume          #+#    #+#             */
/*   Updated: 2023/10/16 14:35:24 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_arraylen(char **src)
{
	int	i;

	i = 0;
	if (src)
		while (src[i])
			i++;
	return (i);
}

void	*ft_clear_array(char **src)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i] != NULL)
		{
			free(src[i]);
			i++;
		}
		src = ft_free(src);
	}
	return (NULL);
}

char	**ft_arrayjoin(char **src, char *s)
{
	char	**res;
	int		i;
	int		len;

	if (!s)
		return (src);
	len = ft_arraylen(src);
	res = ft_calloc(len + 2, sizeof(char *));
	i = 0;
	if (src)
	{
		while (src[i])
		{
			res[i] = ft_strdup(src[i]);
			i++;
		}
	}
	res[i] = ft_strdup(s);
	res[i + 1] = NULL;
	ft_clear_array(src);
	return (res);
}
