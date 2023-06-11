
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

# define DEBUG_ERR -1

# define SUCCESS	1
# define FAIL		0
# define M_FAIL		-1
# define BAD_ARGS	-2
# define FORK_FAIL	-3
# define PIPE_FAIL	-4

# define PERROR		0
# define NO_FREE	1
# define DO_FREE	2

/*/*//*/*//*/*//*/*//*/*//*/*/
//			fontion			//
/*/*//*/*//*/*//*/*//*/*//*/*/

int	err_msg(short type, int err, char *msg);
int	debug(int err, char *msg);

#endif
