
#ifndef ENV_H
# define ENV_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../include/structure.h"
# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>

//--------------------------//
//			fonction		//
//--------------------------//

int	ft_env(char **av, int re_in, int re_out);

//--------------------------//
//			define			//
//--------------------------//

# ifndef ENV
#  define ENV "env"
#  define ENV_PATH "BUILT_IN/env/"
# endif

#endif // ENV_H
