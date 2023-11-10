/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:55 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/10 13:11:23 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//--------------------------//
//			include			//
//--------------------------//

# ifndef _WIN32
#  include <sys/wait.h>
# endif
# include <stdbool.h>
# include "token.h"
# include "../include/err.h"
# include "../built_in/built_in.h"

//--------------------------//
//			define			//
//--------------------------//

# define ISDIR "is a directory"

/*
◦ < doit rediriger l’entrée.
◦ << doit recevoir un délimiteur et lire l’input 
donné jusqu’à rencontrer une ligne
contenant le délimiteur. Cependant, 
l’historique n’a pas à être mis à jour !
◦ > doit rediriger la sortie.
◦ >> doit rediriger la sortie en mode append.
*/

//--------------------------//
//			fonction		//
//--------------------------//

// cmd

int		no_file(char *name);
int		permission_denied(char *name, mode_t *err, int code);
short	set_data_exe(t_exe *data, t_mshell *shell, t_cmd *in);

short	make_new_path(t_mshell *shell);
char	**ex_en_new(char **en);

int		run_cmd(t_cmd *in, t_mshell *shell);
short	cmd_make_node_last(t_cmd **list, char **cmd, t_token *tok);

void	cmd_free(t_cmd **in);
size_t	cmd_node_len(t_cmd *list);
t_cmd	*cmd_make_node(char **cmd, t_token *tok);

short	get_result(int err, char *name, int *f, char *mal);

short	change_av_for_en(t_cmd *in);
void	change_name(int pec, t_cmd *in);
short	change_av_pwd(t_cmd *in, char *pwd);

short	ft_execution(t_cmd *in, t_waitp **wait, short local);
int		find_path(char *name, char **out, char **list, mode_t *err);
int		execution_builtin(t_cmd *in, t_waitp **wait, int cmd_len);

int		change_env_data(t_mshell *data);
short	oldpwd(t_mshell *data);
short	new_pwd(t_mshell *data);

// fd

int		close_fd(int fd);
void	close_all_fd(t_cmd *in);
int		close_old_fd(t_cmd *in);
int		free_and_dup_in_run(t_cmd *in);

// pipe

int		set_pipe(t_cmd **in);
int		set_redir(t_cmd *in);
int		dup_in_out(t_cmd *in);

// pid

int		wait_make_node_last(t_waitp **in, pid_t pid, int flag, char *name);
short	wait_pids(t_waitp *in, short free_f);

//free 

int		free_exe(int err, t_exe *exe);
void	free_t_mshell(t_mshell *shell);
void	free_execution(t_cmd **in, t_mshell *shell);

#endif // EXECUTION_H