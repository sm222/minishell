
#ifndef EXPORT_H
# define EXPORT_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../include/structure.h"
# include "../../lib/lib_ft/libft.h"
# include "../../include/err.h"
# include <sysexits.h>

//--------------------------//
//			fonction		//
//--------------------------//

int		print_env(char **en, int re_out);
int		ft_export(char **av, int re_in, int re_out, char **en);
char	**change_arg_env(char **en, int i, char *new);

//--------------------------//
//			define			//
//--------------------------//

# ifndef EXPORT
#  define EXPORT "export"
# endif

#endif // EXPORT_H