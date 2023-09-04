#ifndef TODO_H
# define TODO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../printf/ft_printf.h"
# include "../include/structure.h"

#include <stdio.h>

# define CORRECT 1
# define INVALID -1 
# define INCORRECT 0
# define FIRST_INDEX 0
# define PASSED_THROUGH 31
# define SINGLE_REDIRECT 's'
# define DOUBLE_REDIRECT 'd'

typedef struct s_loc
{
	char			**decon_cmd;
	t_token			*tokens;
	struct s_loc	*next;
}	t_loc;

int		ft_has_pipe(char *src);
int		ft_arraylen(char **src);
int		ft_redirect_op(char *cmd);
int		ft_invalid_pipe(char *cmd);
int		ft_has_redirect(char *src);
void	ft_check_here_doc(char *src);
int		ft_at_index(char *src, char c);
char	**ft_cmd_deconstruct(char *cmd);
void	ft_purge(char **decon, char *src);
void	ft_pipe_op(char *cmd, t_loc list);
int		ft_at_rev_index(char *src, char c);
char	*ft_get_file(char *cmd, char mode);
int		ft_input(char *src, int start_index);
int		ft_output(char *src, int start_index);
char	*ft_strslice(char *src, int start, int end);
int		ft_file_op(char *cmd, char redirect, char mode);

#endif
