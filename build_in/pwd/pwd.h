
#ifndef PWD_H
# define PWD_H

# include "../../lib/lib_ft/libft.h"
# include <sysexits.h>

int		ft_pwd(char **av, int re_in, int re_out);

# ifndef PWD
#  define PWD "ft_pwd"
#  define PWD_PATH "build_in/pwd/"
# endif

#endif // PWD_H
