/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:19:00 by anboisve          #+#    #+#             */
/*   Updated: 2023/04/11 12:17:41 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDEX_H
# define INDEX_H

# include "unistd.h"

typedef struct s_index
{
	int		x[100];
	int		y[100];
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
}	t_index;

#endif 