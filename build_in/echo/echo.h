
#ifndef ECHO_H
# define ECHO_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>

//--------------------------//
//			fontion			//
//--------------------------//

int	ft_echo(char **av, int re_in, int re_out);

//--------------------------//
//			define			//
//--------------------------//

# ifndef ECHO
#  define ECHO "echo"
#  define ECHO_PATH "build_in/echo/"
# endif

#endif // ECHO_H
