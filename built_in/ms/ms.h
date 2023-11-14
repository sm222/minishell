#ifndef MS_H
# define MS_H

//--------------------------//
//			include			//
//--------------------------//

# include "../../include/structure.h"
# include "../../lib/lib_ft/libft.h"
# include "../../include/err.h"
# include <sysexits.h>
# include <errno.h>

//--------------------------//
//			fonction		//
//--------------------------//

int	ft_ms(char **av, int re_in, int re_out, char **en);
int	ms_edit(char **av, size_t *j);
int	ms_logic(char **av, size_t *j);
int	ms_update(int i);
int	ms_run(char **av, size_t *j);

//--------------------------//
//			define			//
//--------------------------//

# define DIRL "DIRL=(number) - change the lend of the pwd in the prompt\n"
# define COLOR_SYS "C=(number)(number) - change colors of the prompt\n"
# define LOGIC "need 2 string {exit code 0} {exit code 1}\n"
# define RUN "need 1 file {PATH}\n"

# ifndef MS
#  define MS "ms"
# endif

#endif // EXPORT_H
