
#ifndef PWD_H
# define PWD_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>

//--------------------------//
//			fonction		//
//--------------------------//

int		ft_pwd(char **av, int re_in, int re_out);

//--------------------------//
//			define			//
//--------------------------//

# ifndef PWD
#  define PWD "pwd"
#  define PWD_PATH "build_in/pwd/"
# endif

#endif // PWD_H
