/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:23:22 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:23:22 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../include/structure.h"
# include "../../lib/lib_ft/libft.h"
# include "../../include/err.h"
# include <sysexits.h>

//--------------------------//
//			fonction		//
//--------------------------//

int	ft_unset(char **av, int re_in, int re_out, char **en);

//--------------------------//
//			define			//
//--------------------------//

# ifndef UNSET
#  define UNSET "unset"
# endif

#endif // UNSET_H
