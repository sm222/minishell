
#ifndef ALIAS_H
# define ALIAS_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>
# include <errno.h>

//--------------------------//
//			fonction		//
//--------------------------//

int	ft_alias(char **av, int re_in, int re_out, char **en);

//--------------------------//
//			define			//
//--------------------------//

# ifndef ALIAS
#  define ALIAS "alias"
# endif



#endif // ALIAS_H
