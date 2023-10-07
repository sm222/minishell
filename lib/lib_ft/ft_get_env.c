/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:47:27 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/06 20:06:43 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_env(char **en, char *seed)
{
	size_t	i;
	size_t	name;

	i = 0;
	while (en && en[i])
	{
		name = 0;
		while (en[i][name] && en[i][name] != '=')
			name++;
		if (ft_strncmp(en[i], seed, name) == 0 && (!ft_isalnum(seed[name]) \
		&& seed[name] != '_'))
			return (en[i] + name + 1);
		i++;
	}
	return (NULL);
}
