
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

# ifndef  TRUE
#  define TRUE			1
# endif
# ifndef FALSE
#  define FALSE			0
# endif

# define PIPE_NO		0
# define PIPE_IN		1
# define PIPE_OUT		2
# define PIPE_IN_OUT	3
# define BUILT_IN		4

//	byte flag			//
# define BUILT_IN_FLAG	0B00010000

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


typedef struct s_token
{
	int				mode;
	int				pipe_in;
	int				pipe_out;
	int				redi_in;
	int				redi_out;
}	t_token;

typedef struct s_waitp
{
	short			built;
	pid_t			pid;
	struct s_waitp	*next;
}t_waitp;

typedef struct s_exe
{
	int				err;
	int				err_redir;
	char			*ft_path;
	pid_t			pid;
}	t_exe;

typedef struct s_cmd
{
	struct s_cmd	*prev;
	struct s_cmd	*next;
	char			**command;
	int				pipe[2];
	t_token			*tok;
}	t_cmd;

/// @brief pec = prosess exit code
typedef struct s_mshell
{
	char			*s;
	int				pec;
	short			exit;
	char			**en;
	char			**path;
	t_cmd			*cmd_list;
	char			*info;
	char			*tmp;
	t_doc			*doc;
}	t_mshell;



typedef struct s_run
{
	int		err;
	t_waitp	*wait;
	t_cmd	*tmp;
}	t_run;


#endif // STRUCTURE_H
