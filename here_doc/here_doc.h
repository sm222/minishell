/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:27:01 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/10 13:43:43 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

//--------------------------//
//			include			//
//--------------------------//

# include <unistd.h>
# include <stdio.h>
# include "../lib/lib_ft/libft.h"
# include "../include/structure.h"
# include "../include/err.h"
# include "../readline/history.h"
# include "../readline/readline.h"

//--------------------------//
//			define			//
//--------------------------//

//--------------------------//
//			fonction		//
//--------------------------//

//ft you shoud use

int	make_here_doc(char inter, char *stop);
int	edit_here_doc(t_doc *doc, char *stop, short inter);
int	free_here_doc(short unlink_f);

// - - - - - - - - - - - -
int	close_and_exit(int fd);

#endif // HERE_DOC_H
