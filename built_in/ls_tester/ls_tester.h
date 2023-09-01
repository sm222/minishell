/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tester.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:21:35 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/31 09:21:38 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LS_TESTER_H
# define LS_TESTER_H

//--------------------------//
//			include			//
//--------------------------//

# include <unistd.h>
# include <stdio.h>
# include "../../lib/lib_ft/libft.h"
# include "../../include/err.h"
# include "../../include/structure.h"

//--------------------------//
//			fonction		//
//--------------------------//

int		ft_ls_tester(char **av, int re_in, int re_out, char **en);

//--------------------------//
//			define			//
//--------------------------//

# ifndef LS_TESTER
#  define LS_TESTER "pwd"
# endif

#endif // LS_TESTER_H
