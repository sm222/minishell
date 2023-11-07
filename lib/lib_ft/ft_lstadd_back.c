/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:53:41 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/07 15:27:58 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *neww)
{
	t_list	*last;

	if (lst && *lst)
	{
		last = ft_lstlast(*lst);
		last->next = neww;
	}
	else
		*lst = neww;
}
