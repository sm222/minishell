#ifndef TODO_H
# define TODO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "include/structure.h"

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
	t_token	token;
	int		open_mark;
}	t_decon;

char	*ft_arg_op(char *cmd);
void	ft_pipe_op(char *cmd);
int		ft_has_flags(char *src);
void	ft_purge(t_decon *decon);
int		ft_count_flags(char *src);
t_token	ft_redirect_op(char *cmd);
int		ft_has_redirect(char *src);
int		ft_list_count(t_flag *head);
int		ft_at_index(char *src, char c);
char	**ft_cmd_deconstruct(char *cmd);
int		ft_at_rev_index(char *src, char c);
char	*ft_get_file(char *cmd, char mode);
char	**ft_cmd_reconstruct(t_decon decon);
void	ft_flag_op(t_flag **flags, char *cmd);
void	ft_add_flag(char *src, t_flag **flags);
char	*ft_strslice(char *src, int start, int end);
int		ft_file_op(char *cmd, char redirect, char mode);

#endif
