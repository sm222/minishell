/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:28:10 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/14 13:10:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

/*/*//*/*//*/*//*/*//*/*//*/*/
//			include			//
/*/*//*/*//*/*//*/*//*/*//*/*/

# include <stdio.h>
# include <sysexits.h>
# include <fcntl.h>
# include "../lib/lib_ft/libft.h"

/*/*//*/*//*/*//*/*//*/*//*/*/
//			define			//
/*/*//*/*//*/*//*/*//*/*//*/*/

# define MS_NAME "minishell "
# define FILE_DEF ".debug_minishell"
# define ERR_CNF "command not found: "
# define ERR_NSFD "No such file or directory: "
# define BAD_LIST_UNSET "éèÈÉçÇ^.!@#$%?&*()-+=\"\\/;,àÀ||¤{}[]¬ 	"
# define BAD_LIST_EXPORT "éèÈÉçÇ^.!@#$%?&*()-+/\";,àÀ||¤{}[]¬ 	"

# define DEBUG_ERR -1

# define SUCCESS	1
# define FAIL		0
# define M_FAIL		-1
# define BAD_ARGS	-2
# define FORK_FAIL	-3
# define PIPE_FAIL	-4
# define NO_ASS		-5
# define OPEN_FAIL	-6
# define ERR_PD		-7
# define ERR_NO_TXT	-8

# define PERROR		0
# define NO_FREE	1
# define DO_FREE	2

# define NO_UNLINK	0
# define UNLINK		1

/*/*//*/*//*/*//*/*//*/*//*/*/
//			fonction		//
/*/*//*/*//*/*//*/*//*/*//*/*/

int	err_msg(short type, int err, char *msg);
int	debug(int err, char *msg, char *file);

#endif
