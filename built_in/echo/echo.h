
#ifndef ECHO_H
# define ECHO_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>

//--------------------------//
//			fonction		//
//--------------------------//

int	ft_echo(char **av, int re_in, int re_out, char **en);

//--------------------------//
//			define			//
//--------------------------//

# ifndef ECHO
#  define ECHO "echo"
# endif

#endif // ECHO_H
