/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:28:21 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:28:21 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# ifndef _WIN32
#  include <sys/wait.h>
# endif

//--------------------------//
//			include			//
//--------------------------//

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include "readline/readline.h"
# include "readline/history.h"

//--------------------------//
//			define			//
//--------------------------//

# define SYS       0		// t_mshell struct
# define PATH      1		// path split with the ':'
# define PEC       2		// process exit code
# define ENV_C     3		// copy of the env
# define EX_F      4		// tell if the program end
# define DOC       5		// here_dock
# define SIG       6		// signal_ft
# define PARSE     7		// t_loc struct
# define CLEAN     8		// clean_shell ft
# define FREE_DOC  9		// ft use to free the here_doc
# define DOC_FILE  10		// terminating word for here_doc
# define ALIAS_VAR 11		// use to set and get alias value

//		SIG		//

# ifndef CMD
#  define CMD 9
# endif
# ifndef CHILD
#  define CHILD 3
# endif
# ifndef HERE_DOC
#  define HERE_DOC 6
# endif

//--------------------------//
//			colors			//
//--------------------------//

//ty for that https://github.com/iLucasPires/minishell/blob/e6906a30b2335a9dae38fb5203a6f89062fef7cd/project/includes/minishell_colors.h#L14
# ifndef COLORS
#  define COLORS
#  define RED	"\001\e[31m\002"
#  define GRN	"\001\e[32m\002"
#  define YEL	"\001\e[33m\002"
#  define BLU	"\001\e[34m\002"
#  define MAG	"\001\e[35m\002"
#  define CYN	"\001\e[36m\002"
#  define WHT	"\001\e[37m\002"
#  define ORG	"\001\e[38;5;202m\002"
#  define PIK	"\001\e[38;5;176m\002"
#  define TOX	"\001\e[38;5;51m\002"
#  define RESET	"\001\e[0m\022"
#  define CLE	"\001\e[1;1H\x1b[2J\002"
#  define GIT	"\001\e[38;5;82m\002"
#  define GIT_B	"\001\e[38;5;94m\002"
# endif

//--------------------------//
//			bool			//
//--------------------------//

//--------------------------//
//			pipes			//
//--------------------------//

# define PIPE_NO		0
# define PIPE_IN		1
# define PIPE_OUT		2
# define PIPE_IN_OUT	3
# define BUILT_IN		4

//	byte flag			//
# define BUILT_IN_FLAG	0x10

# define PROMPT "$ "

//--------------------------//
//			struct			//
//--------------------------//

typedef struct s_doc
{
	struct stat		start;
	struct stat		last;
	char			*f_name;
	int				i;
	int				fd;
	struct s_doc	*next;
}		t_doc;

/// @brief use to find if is a built in and redir
/// @param mode 		byte flag
/// @param pipe_in 		last cmd output
/// @param pipe_out 	this cmd output
/// @param redi_in 		cmd redir input
/// @param redi_out 	cmd redir output
/// @param redi_doc 	fd of here_doc
typedef struct s_token
{
	int				mode;
	int				pipe_in;
	int				pipe_out;
	int				redi_in;
	int				redi_out;
	int				redi_doc;
}	t_token;

/// @brief linklist use for waitpid
/// @param buildt 		buildin
/// @param pid 			pid of the prosses
/// @param next 		next node
typedef struct s_waitp
{
	short			built;
	pid_t			pid;
	char			*name;
	struct s_waitp	*next;
}	t_waitp;

/// @brief use in execution 
/// @param err 			err code
/// @param err_redir 	
/// @param ft_path 		path of the cmd
/// @param pid 			pid of the cmd run
typedef struct s_exe
{
	int				err;
	int				err_redir;
	char			*ft_path;
	pid_t			pid;
}	t_exe;

/// @brief use for linklist of cmd
/// @param prev 		one before
/// @param next 		one after
/// @param commend 		cmd send to exeve
/// @param pipe 		use to store 2 fd
/// @param tok 			token use to redir
typedef struct s_cmd
{
	struct s_cmd	*prev;
	struct s_cmd	*next;
	char			**command;
	int				pipe[2];
	t_token			*tok;
}	t_cmd;

typedef struct s_col_sys
{
	char	*red;
	char	*grn;
	char	*yel;
	char	*blu;
	char	*mag;
	char	*pik;
	char	*wht;
	char	*tox;
	char	*git;
	char	*git_b;
	char	*org;
	char	*c1;
	char	*c2;
	char	*c3;
	char	*c4;
	char	*c5;
}	t_col_sys;

/// @brief use in the shell
/// @param s 		readline output
/// @param pec 		prosess exit code
/// @param exit 	bool to know if the shell need to exit
/// @param en 		enviroment
/// @param pwd 		prompt dir
/// @param prompt 	prompt tmp var
/// @param doc 		link list variable
typedef struct s_mshell
{
	char			*s;
	char			*s_in;
	size_t			dir_len;
	char			*rest;
	int				pec;
	short			exit;
	char			**en;
	char			**path;
	t_cmd			*cmd_list;
	char			*pwd;
	char			*prompt;
	t_doc			*doc;
	short			re_draw;
	char			*git_status;
	t_waitp			*keep_wait;
	char			**alias;
	char			*compile_dir;
	t_col_sys		sys_color;
	struct termios	*termios;
}	t_mshell;

/// @brief use in run_cmd
/// @param err 		err code
/// @param wait 	waitpid link list
/// @param tmp 		use to navigate the link list
typedef struct s_run
{
	int		err;
	t_waitp	*wait;
	t_cmd	*tmp;
}	t_run;

#endif // STRUCTURE_H
