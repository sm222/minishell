
#ifndef MINISHELL_H
# define MINISHELL_H

//--------------------------//
//			include			//
//--------------------------//

# include "err.h"

//--------------------------//
//			lib				//
//--------------------------//

# include "../lib/lib_ft/libft.h"
# include "../readline/history.h"
# include "../readline/readline.h"
# include "../execution/execution.h"
# include "../here_doc/here_doc.h"

# define DEV_CHMOD	0644

//TODO: zsh: command not found:

//--------------------------//
//			define			//
//--------------------------//


# define MADE_BY "		made by		"
# define MADE_BY_NANE "\x1B[34m anboisve \x1B[32m brheaume\n"

# define L0M "███    ███ "
# define L1M "████  ████ "
# define L2M "██ ████ ██ "
# define L3M "██  ██  ██ "
# define L4M "██      ██ "

# define L0I "██ "
# define L1I "██ "
# define L2I "██ "
# define L3I "██ "
# define L4I "██ "

# define L0N "███    ██ "
# define L1N "████   ██ "
# define L2N "██ ██  ██ "
# define L3N "██  ██ ██ "
# define L4N "██   ████ "

# define L0S "███████ "
# define L1S "██      "
# define L2S "███████ "
# define L3S "     ██ "
# define L4S "███████ "

# define L0H "██   ██ "
# define L1H "██   ██ "
# define L2H "███████ "
# define L3H "██   ██ "
# define L4H "██   ██ "

# define L0E "███████ "
# define L1E "██      "
# define L2E "█████   "
# define L3E "██      "
# define L4E "███████ "

# define L0L "██      "
# define L1L "██      "
# define L2L "██      "
# define L3L "██      "
# define L4L "███████ "

typedef struct s_logo
{
	char		*tmp;
	long long	con;
	char		*color[11];
	char		*m[5];
	char		*i[5];
	char		*n[5];
	char		*s[5];
	char		*h[5];
	char		*e[5];
	char		*l[5];
	int			nb[9];
}t_logo;

//--------------------------//
//			fonction		//
//--------------------------//

short	reset_data_main(t_mshell *shell);
int		get_env_path(t_mshell *data);
void	print_logo(char *seed);

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