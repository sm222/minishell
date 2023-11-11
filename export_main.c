/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:56:24 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/10 22:56:24 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	export_main(t_mshell *data)
{
	char	**av;
	char	*new;

	new = NULL;
	av = NULL;
	ft_printf(NO_PRINT, "%oex\bCONPILE_DIR="CONPILE_DIR, &new);
	av = ft_split(new, '\b');
	ft_export(av, 0, 1, data->en);
	data->en = ft_return_ptr(NULL, ENV_C);
	av = (char **)ft_double_sfree((void **)av);
	new = NULL;
	ft_printf(NO_PRINT, "%oex\bV_MINI="V_MINI, &new);
	av = ft_split(new, '\b');
	ft_export(av, 0, 1, data->en);
	data->en = ft_return_ptr(NULL, ENV_C);
	av = (char **)ft_double_sfree((void **)av);
	return (0);
}
