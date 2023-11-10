#ifndef EDIT_H
# define EDIT_H

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

int	ft_edit(char **av, int re_in, int re_out, char **en);
int	shell_edit(char **av, size_t *j);
int	edit_logic(char **av, size_t *j);
int	edit_update(void);
int	edit_run(char **av, size_t *j);

//--------------------------//
//			define			//
//--------------------------//

# define DIRL "DIRL=(number) - change the lend of the pwd in the prompt\n"
# define COLOR_SYS "C=(number)(number) - change colors of the prompt\n"
# define LOGIC "need 2 string {exit code 0} {exit code 1}\n"
# define RUN "need 1 file {PATH}\n"

# ifndef EDIT
#  define EDIT "edit"
# endif

#endif // EXPORT_H
