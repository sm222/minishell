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

//--------------------------//
//			include			//
//--------------------------//

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <sys/wait.h>
# include "readline/readline.h"
# include "readline/history.h"
# include "shelldata.h"

//--------------------------//
//			define			//
//--------------------------//

//	use for ft_return_ptr
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

// use in ft_signal_handler
# ifndef SIG_SHELL
#  define SIG_SHELL 1
#  define CMD       9
#  define CHILD     3
#  define HERE_DOC  6
# endif

//--------------------------//
//			colors			//
//--------------------------//

//ty for that https://github.com/iLucasPires/minishell/blob/e6906a30b2335a9dae38fb5203a6f89062fef7cd/project/includes/minishell_colors.h#L14
# ifndef COLORS
#  define COLORS
#  define CS	"\001" //*start code
#  define CE	"\002" //*end   code
#  define RED	CS"\e[31m"CE
#  define GRN	CS"\e[32m"CE
#  define YEL	CS"\e[33m"CE
#  define BLU	CS"\e[34m"CE
#  define MAG	CS"\e[35m"CE
#  define CYN	CS"\e[36m"CE
#  define WHT	CS"\e[37m"CE
#  define ORG	CS"\e[38;5;202m"CE
#  define PIK	CS"\e[38;5;176m"CE
#  define TOX	CS"\e[38;5;51m"CE
#  define RESET	CS"\e[0m\022"CE
#  define CLE	CS"\e[1;1H\x1b[2J"CE
#  define GIT	CS"\e[38;5;82m"CE
#  define GIT_B	CS"\e[38;5;94m"CE
# endif

//--------------------------//
//			bool			//
//--------------------------//

//--------------------------//
//			pipes			//
//--------------------------//

# define PIPE_NO		0	//index of byte in mode for token
# define PIPE_IN		1	//index of byte in mode for token
# define PIPE_OUT		2	//index of byte in mode for token
# define PIPE_IN_OUT	3	//index of byte in mode for token
# define BUILT_IN		4	//index of byte in mode for token

//	byte flag			//
# define BUILT_IN_FLAG	0x10

typedef	char* name;

//--------------------------//
//			struct			//
//--------------------------//

typedef struct s_doc
{
	struct stat		start;		//use to see if file is still useable
	struct stat		last;		//use to see if file is still useable
	char			*f_name;	//name
	int				i;			//file number
	int				fd;			//fd of file
	struct s_doc	*next;		//next node
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
	int32_t			mode;		//byte flag
	int				pipe_in;	//fd
	int				pipe_out;	//fd
	int				redi_in;	//fd
	int				redi_out;	//fd
	int				redi_doc;	//fd
}	t_token;

/// @brief linklist use for waitpid
/// @param buildt 		buildin
/// @param pid 			pid of the prosses
/// @param next 		next node
typedef struct s_waitp
{
	int				built;	//use to store if is a buildin
	pid_t			pid;	//pid
	char			*name;	//name of the ft
	struct s_waitp	*next;	//next one
}	t_waitp;

/// @brief use in execution 
/// @param err 			err code
/// @param err_redir	
/// @param ft_path		path of the cmd
/// @param pid			pid of the cmd run
typedef struct s_exe
{
	int				err;		//err code
	int				err_redir;	//
	char			*ft_path;	// path of cmd if find
	pid_t			pid;		// pid code
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
	char			**command;	//av of command, av[0] is use to find path
	int				pipe[2];	//use to store 2 fd
	t_token			*tok;		//token of command
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
	char	*c1;	// color prompt
	char	*c2;	// color prompt
	char	*c3;	// color prompt
	char	*c4;	// color prompt
	char	*c5;	// color prompt
}	t_col_sys;

typedef struct s_mshell
{
	size_t			*s_line;		//pointer to line parsing //* use for ms jump
	char			*s;				//readline output
	int				pec;			//prosess exit code
	short			exit;			//exit flag could be switch for a bool
	char			**en;			//env copy
	char			*pwd;			//pwd use in readline
	t_doc			*doc;			//heredoc linklist
	char			**av;			//pointer to argv from main
	char			*s_in;			//if cmd put in here shell will skip readline
	char			*rest;			// ----need docu
	char			**path;			//$PATH split on ':'
	size_t			dir_len;		//change len of pwd in readline
	char			*prompt;		// all text use in readline to make the prompt
	short			re_draw;		//set to 1 if shell run cmd else 0, use to fix problem were readline print more then onece
	char			**alias;		//unuse yet
	struct termios	*termios;		//unuse -- can use later
	t_cmd			*cmd_list;		//link list of cmd for execution
	t_col_sys		sys_color;		//use to costomise the shell
	t_waitp			*keep_wait;		//waitpid list use at the end of execution
	char			*git_status;	//use if .git was find and show in the prompt
	char			*compile_dir;	//were is the shell was compile
	int				isatty;			//use to know if the shell is pipe or not
}	t_mshell;

/// @brief use in run_cmd
/// @param err 		err code
/// @param wait 	waitpid link list
/// @param tmp 		use to navigate the link list
typedef struct s_run
{
	int		err;		//err code
	t_waitp	*wait;		//link list
	t_cmd	*tmp;		//place holder while it run
}	t_run;

#endif // STRUCTURE_H
