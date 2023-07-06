
#ifndef EXIT_H
# define EXIT_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>

int	ft_exit(char **av);

# ifndef EXIT
#  define EXIT "exit"
#  define EXIT_PATH "build_in/exit/"
# endif


#endif // EXIT_H
