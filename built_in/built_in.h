/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:23:29 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/23 08:35:41 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

//--------------------------//
//			include			//
//--------------------------//

# include "export/export.h"
# include "unset/unset.h"
# include "echo/echo.h"
# include "exit/exit.h"
# include "pwd/pwd.h"
# include "env/env.h"
# include "cd/cd.h"
# include "ms/ms.h"
# include "alias/alias.h"

//--------------------------//
//			define			//
//--------------------------//


//don't use. need to update
# define PATH_BIN "/tmp/binmini/"

#endif // BUILT_IN_H
