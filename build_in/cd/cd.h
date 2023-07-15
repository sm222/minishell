
#ifndef CD_H
# define CD_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>
# include <errno.h>

//--------------------------//
//			fontion			//
//--------------------------//

int	ft_cd(char **av, int re_in, int re_out);

//--------------------------//
//			define			//
//--------------------------//

# ifndef CD
#  define CD "cd"
#  define CD_PATH "build_in/cd/"
# endif

#endif // CD_H