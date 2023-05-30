
#ifndef EXECUTION_H
# define EXECUTION_H

//--------------------------//
//			include			//
//--------------------------//

# include "../lib/lib_ft/libft.h"
# include "../include/err.h"

//--------------------------//
//			define			//
//--------------------------//

# define SET_IN 1
# define SET_OUT 2
# define SET_HERE_DOC 3
# define SET_APPEND 4

//--------------------------//
//			struct			//
//--------------------------//

typedef struct s_cmd
{
	struct s_cmd	*prev;
	struct s_cmd	*next;
	char			**command;
	int				order;
	int				pipe[2];
	char			mode;
	char			*in_file;
}	t_cmd;

/*
◦ < doit rediriger l’entrée.
◦ > doit rediriger la sortie.
◦ << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne
contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !
◦ >> doit rediriger la sortie en mode append.
*/

/*/*//*/*//*/*//*/*//*/*//*/*/
void	cmd_free(t_cmd *in);
size_t	cmd_node_len(t_cmd *list);
t_cmd	*cmd_make_node(char **cmd, int order);
int		find_path(char *name, char **out, char **list);
short	cmd_make_node_last(t_cmd **list, char **cmd, int order);
/*/*//*/*//*/*//*/*//*/*//*/*/

#endif // EXECUTION_H