
#ifndef MINISHELL_H
# define MINISHELL_H

//--------------------------//
//			include			//
//--------------------------//

# include "include/err.h"

//--------------------------//
//			lib				//
//--------------------------//

# include "lib/lib_ft/libft.h"
# include "readline/history.h"
# include "readline/readline.h"
# include "execution/execution.h"

//--------------------------//
//			tools			//
//--------------------------//

# include "C_tools/C_tool.h"
# define dev_chmod 0644

//--------------------------//
//			define			//
//--------------------------//

# define SYS 0



# define PROMPT "$ "
# define MS_NAME "Minishell: "

//TODO: zsh: command not found:

//--------------------------//
//			struct			//
//--------------------------//

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

//--------------------------//
//			fontion			//
//--------------------------//

int	get_env_path(t_mshell *data);

#endif // MINISHELL_H

/*
readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs
*/