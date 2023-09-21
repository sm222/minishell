
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

//--------------------------//
//			define			//
//--------------------------//

# define SYS   0		// t_mshell struct
# define PATH  1		// path split with the ':'
# define PEC   2		// process exit code
# define ENV_C 3		// copy of the env
# define EX_F  4		// tell if the program end
# define DOC   5		// here_dock

//--------------------------//
//			colors			//
//--------------------------//

# ifndef COLORS
#  define COLORS
#  define RED	"\x1B[31m"
#  define GRN	"\x1B[32m"
#  define YEL	"\x1B[33m"
#  define BLU	"\x1B[34m"
#  define MAG	"\x1B[35m"
#  define CYN	"\x1B[36m"
#  define WHT	"\x1B[37m"
#  define ORG	"\x1b[38;5;202m"
#  define PIK	"\x1b[38;5;176m"
#  define TOX	"\x1b[38;5;190m"
#  define RESET	"\x1B[0m"
#  define CLE	"\e[1;1H\e[2J"
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
typedef struct s_token
{
	int				mode;
	int				pipe_in;
	int				pipe_out;
	int				redi_in;
	int				redi_out;
}	t_token;

/// @brief linklist use for waitpid
/// @param buildt 		buildin
/// @param pid 			pid of the prosses
/// @param next 		next node
typedef struct s_waitp
{
	short			built;
	pid_t			pid;
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
	int				pec;
	short			exit;
	char			**en;
	char			**path;
	t_cmd			*cmd_list;
	char			*pwd;
	char			*prompt;
	t_doc			*doc;
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