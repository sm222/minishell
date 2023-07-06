
#ifndef EXECUTION_H
# define EXECUTION_H

//--------------------------//
//			include			//
//--------------------------//

//https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive

# ifndef _WIN32
#  include <sys/wait.h>
# endif
# include "../include/minishell.h"
# include "../build_in/build_in.h"

//--------------------------//
//			define			//
//--------------------------//

//--------------------------//
//			struct			//
//--------------------------//

# ifndef EXE_STRUC
#  define EXE_STRUC
typedef struct s_cmd
{
	struct s_cmd	*prev;
	struct s_cmd	*next;
	char			**command;
	int				pipe[2];
	t_token			*tok;
}	t_cmd;
#endif

typedef struct s_waitp
{
	pid_t			pid;
	struct s_waitp	*next;
}t_waitp;

typedef struct s_exe
{
	int			err;
	char		*ft_path;
	pid_t		pid;
}	t_exe;

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

short	ft_execution(t_cmd *in, t_waitp **wait);
int		ft_execution_buildin(t_cmd *in, t_waitp **wait, int cmd_len);

// fd
int		close_fd(int fd);
void	close_all_fd(t_cmd *in);
int		close_old_fd(t_cmd *in);

// pipe

int		set_pipe(t_cmd **in);
int		set_redir(t_cmd *in);
int		dup_in_out(t_cmd *in);

// pid

int		wait_make_node_last(t_waitp **in, pid_t pid);
short	wait_pids(t_waitp *in, short free_f);

//free

int		free_exe(int err, t_exe *exe);

#endif // EXECUTION_H