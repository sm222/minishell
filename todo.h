#ifndef TODO_H
# define TODO_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

#include <stdio.h>

# define CORRECT 1
# define INVALID -1 
# define INCORRECT 0
# define NODE_SIZE 1
# define FIRST_INDEX 0
# define REST_OF_CMD 3
# define PASSED_THROUGH 31 //or 26 if 31 doesn't work

typedef struct s_flag
{
	char			*flag;
	struct s_flag	*next;
	struct s_flag	*prev;
}	t_flag;

typedef struct s_decon
{
	char	*cmd;
	t_flag	*flags;
	char	*arg;
	int		open_mark;
}	t_decon;

char	*ft_arg_op(char *cmd);
void	ft_pipe_op(char *cmd);
int		ft_has_flags(char *src);
int		ft_redirect_op(char *cmd);
int		ft_has_redirect(char *src);
int		ft_at_index(char *src, char c);
char	**ft_cmd_deconstruct(char *cmd);
char	**ft_cmd_reconstruct(t_decon decon);
void	ft_flag_op(t_flag **flags, char *cmd);
void	ft_add_flag(char *src, t_flag **flags);
void	ft_purge(char *first_cmd, char *sec_cmd);
char	*ft_strslice(char *src, int start, int end);

#endif
