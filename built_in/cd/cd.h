
#ifndef CD_H
# define CD_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../lib/lib_ft/libft.h"
# include "../../include/err.h"
# include <sysexits.h>
# include <errno.h>

//--------------------------//
//			fonction		//
//--------------------------//

int	ft_cd(char **av, int re_in, int re_out, char **en);

//--------------------------//
//			define			//
//--------------------------//

# ifndef CD
#  define CD "cd"
#  define PWD_GIT PATH_MAX + (10 + 1)
# endif

#endif // CD_H