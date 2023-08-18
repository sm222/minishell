#ifndef TODO_H
# define TODO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "printf/ft_printf.h"
# include "include/structure.h"

#include <stdio.h>

# define CORRECT 1
# define INVALID -1 
# define INCORRECT 0
# define NODE_SIZE 1
# define FIRST_INDEX 0
# define REST_OF_CMD 3
# define PASSED_THROUGH 31 //or 26 if 31 doesn't work

typedef struct s_decon
{
	char			*src;
	struct s_decon	*next;
}	t_decon;

char	*ft_arg_op(char *cmd);
void	ft_pipe_op(char *cmd);
int		ft_has_flags(char *src);
void	ft_purge(t_decon *decon);
int		ft_count_flags(char *src);
t_token	ft_redirect_op(char *cmd);
int		ft_has_redirect(char *src);
int		ft_list_count(t_decon *head);
int		ft_at_index(char *src, char c);
t_decon	ft_cmd_deconstruct(char *cmd);
int		ft_at_rev_index(char *src, char c);
char	*ft_get_file(char *cmd, char mode);
char	**ft_cmd_reconstruct(t_decon decon);
void	ft_add_slice(char *src, t_decon *decon);
char	*ft_strslice(char *src, int start, int end);
int		ft_file_op(char *cmd, char redirect, char mode);

#endif
