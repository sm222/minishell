
#ifndef EXECUTION_H
# define EXECUTION_H

//--------------------------//
//			include			//
//--------------------------//

//https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive

# ifndef _WIN32
#  include <sys/wait.h>
# endif
# include "token.h"
# include "../include/err.h"
# include "../built_in/built_in.h"

//--------------------------//
//			define			//
//--------------------------//

/*
◦ < doit rediriger l’entrée.
◦ << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne
contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !
◦ > doit rediriger la sortie.
◦ >> doit rediriger la sortie en mode append.
*/

//--------------------------//
//			fonction		//
//--------------------------//

// cmd


int		run_cmd(t_cmd *in, int *pec);
void	cmd_free(t_cmd **in);
size_t	cmd_node_len(t_cmd *list);
t_cmd	*cmd_make_node(char **cmd, t_token *tok);
short	cmd_make_node_last(t_cmd **list, char **cmd, t_token *tok);

short get_result(int err, char *name, int *f, char *mal);

short	change_av_for_en(t_cmd *in);
void	change_name(int pec, t_cmd *in);
short	change_av_pwd(t_cmd *in, char *pwd);

short	ft_execution(t_cmd *in, t_waitp **wait, short local);
int		find_path(char *name, char **out, char **list);
int		execution_builtin(t_cmd *in, t_waitp **wait, int cmd_len);

int		change_env_data(t_mshell *data);

// fd

int		close_fd(int fd);
void	close_all_fd(t_cmd *in);
int		close_old_fd(t_cmd *in);

// pipe

int		set_pipe(t_cmd **in);
int		set_redir(t_cmd *in);
int		dup_in_out(t_cmd *in);

// pid

int		wait_make_node_last(t_waitp **in, pid_t pid, int l);
short	wait_pids(t_waitp *in, short free_f);

//free

int		free_exe(int err, t_exe *exe);
void	free_t_mshell(t_mshell *shell);

#endif // EXECUTION_H