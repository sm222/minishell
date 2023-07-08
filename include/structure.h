
#ifndef STRUCTURE_H
# define STRUCTURE_H


# ifndef _WIN32
#  include <sys/wait.h>
# endif

//--------------------------//
//			define			//
//--------------------------//

# define SYS 0			//
# define PATH 1			// path split with the ':'
# define PEC 2			// pid exit code
//	byte flag			//
# define SET_IN 1		//
# define PIPE 2			//
# define SET_HERE_DOC 3	//
# define SET_APPEND 4	//

//--------------------------//
//			define			//
//--------------------------//

# ifndef  TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

# define PIPE_NO 0
# define PIPE_IN 1
# define PIPE_OUT 2
# define PIPE_IN_OUT 3
# define BUILD_IN 4

# define F_MODE 1	//free mode
# define NO_FILE 0

# define PROMPT "$ "

//--------------------------//
//			struct			//
//--------------------------//

typedef struct s_token
{
	int		mode;
	int		pipe_in;
	int		pipe_out;
	int		redi_in;
	int		redi_out;
}	t_token;

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
	char	*s;
	int		pec;
	char	**en;
	char	**path;
	t_cmd	*cmd_list;
	char	*info;
	char	*tmp;

}	t_mshell;


#endif // STRUCTURE_H