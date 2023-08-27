
#ifndef HERE_DOC_H
# define HERE_DOC_H

//--------------------------//
//			include			//
//--------------------------//

# include "../lib/lib_ft/libft.h"
# include "../include/structure.h"
# include "../include/err.h"
# include "../readline/history.h"
# include "../readline/readline.h"

//--------------------------//
//			define			//
//--------------------------//

//--------------------------//
//			fonction		//
//--------------------------//

t_doc	*new_doc(int *f, int i);

short	make_here_doc(int i, char *stop);
short	edit_here_doc(t_doc *doc, char *stop);
int		get_here_doc(int i);
int		free_here_dock(short unlink_f);


#endif // HERE_DOC_H
