
#ifndef EXECUTION_H
# define EXECUTION_H

//--------------------------//
//			include			//
//--------------------------//

//https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive

# ifdef unix
#  include <sys/wait.h>
# endif
# include "token.h"
# include "../include/err.h"
# include "../lib/lib_ft/libft.h"

//--------------------------//
//			define			//
//--------------------------//

# define PATH 1

# define SET_IN 1
# define PIPE 2
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
	int				pipe[2];
	t_token			*tok;
}	t_cmd;

typedef struct s_waitp
{
	pid_t			pid;
	struct s_waitp	*next;
}t_waitp;


/*
◦ < doit rediriger l’entrée.
◦ << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne
contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !
◦ > doit rediriger la sortie.
◦ >> doit rediriger la sortie en mode append.
*/

//--------------------------//
//			fontion			//
//--------------------------//

int		run_cmd(t_cmd *in);
void	cmd_free(t_cmd **in);
size_t	cmd_node_len(t_cmd *list);
t_cmd	*cmd_make_node(char **cmd, t_token *tok);
int		find_path(char *name, char **out, char **list);
short	cmd_make_node_last(t_cmd **list, char **cmd, t_token *tok);
// pipe
int	ft_redir(t_cmd *in);

// pid
int		wait_make_node_last(t_waitp **in, pid_t pid);
short	wait_pids(t_waitp *in, short free_f);



#endif // EXECUTION_H