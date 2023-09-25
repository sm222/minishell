
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

//ft you shoud use
int		get_here_doc(int i);
int		free_here_doc(short unlink_f);
short	make_here_doc(int i, char inter, char *stop);

t_doc	*new_doc(int *f, int i);
short	edit_here_doc(t_doc *doc, char *stop, short inter);

#endif // HERE_DOC_H
