/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:21:10 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:21:10 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../include/structure.h"
# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>

//--------------------------//
//			fonction		//
//--------------------------//

int	ft_env(char **av, int re_in, int re_out, char **en);

//--------------------------//
//			define			//
//--------------------------//

# ifndef ENV
#  define ENV "env"
# endif

#endif // ENV_H
