/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:55:49 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/19 11:28:10 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_doc(char *s, size_t len)
{
	short	tok;

	tok = 0;
	if (len == 0)
		return (0);
	while (len--)
	{
		if (s[len] == '\'' && tok == 0)
			tok = '\'';
		else if (s[len] == '"' && tok == 0)
			tok = '"';
		else if (tok == s[len])
			tok = 0;
		else if (tok == 0 && len > 0 && s[len] == '<' && s[len - 1] == '<')
			return (1);
		else if (tok == 0 && s[len] == '$')
			break ;
	}
	return (0);
}
