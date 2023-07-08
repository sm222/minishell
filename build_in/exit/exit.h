
#ifndef EXIT_H
# define EXIT_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../include/structure.h"
# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>

int	ft_exit(char **av, int re_in, int re_out);


# ifndef EXIT
#  define EXIT "exit"
#  define EXIT_PATH "build_in/exit/"
# endif


#endif // EXIT_H
