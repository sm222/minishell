/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:54:43 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/29 21:40:26 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

static size_t len_to_c(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
		{
			i++;
			printf("=%s\n", s + i);
			break ;
		}
		i++;
	}
	printf("-%s\n", s + i);
	return (i);
}

short	put_alias(char **str, char **alias_v)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*tmp;

	i = 0;
	j = 0;
	if (!str || !*str || !alias_v)
		return (BAD_ARGS);
	tmp = *str;
	while (tmp && tmp[i])
	{
		j = 0;
		while (alias_v && alias_v[j])
		{
			len = len_to_c(alias_v[j], '=');
			if (ft_strncmp(tmp + i, alias_v[j], len) == 0 && \
				(tmp[len] == ' ' || tmp[len] == '\0'))
				printf("pug\n");
			j++;
		}
		i++;
	}
	return (0);
}

void	set_alias(t_mshell *shell)
{
	char	**av;

	shell->alias = ft_calloc(1, sizeof(char *));
	ft_return_ptr(shell->alias, ALIAS_VAR);
	av = ft_split("ms\b-r\b"CONPILE_DIR"/.config/.msrc", '\b');
	ft_ms(av, 0, 1, shell->en);
	ft_double_sfree((void **)av);
}
