
#ifndef EXIT_H
# define EXIT_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../include/structure.h"
# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>

//--------------------------//
//			fonction		//
//--------------------------//

int	ft_exit(char **av, int re_in, int re_out, char **en);

//--------------------------//
//			define			//
//--------------------------//

# define NUMBER "0123456789" 
# ifndef EXIT
#  define EXIT "exit"
# endif

#endif // EXIT_H
