
#ifndef STRUCTURE_H
# define STRUCTURE_H

# ifndef _WIN32
#  include <sys/wait.h>
# endif

//--------------------------//
//			define			//
//--------------------------//

# define SYS   0		// t_mshell struct
# define PATH  1		// path split with the ':'
# define PEC   2		// process exit code
# define ENV_C 3		// copy of the env
# define EX_F  4		// tell if the program end
# define DOC   5		// here_dock
//	byte flag			//

//--------------------------//
//			define			//
//--------------------------//

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

# define PROMPT "$ "

//--------------------------//
//			struct			//
//--------------------------//

typedef struct s_doc
{
	char			*f_name;
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
}t_run;


#endif // STRUCTURE_H
