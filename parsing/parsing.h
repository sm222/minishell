#ifndef TODO_H
# define TODO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/lib_ft/libft.h"
# include "../include/structure.h"

#include <stdio.h>

# define NODE 1
# define CORRECT 1
# define INVALID -1 
# define INCORRECT 0
# define CHAR_LIMIT 32 // space is the last char not included
# define FIRST_INDEX 0
# define PASSED_THROUGH 31
# define SINGLE_REDIRECT 115 // ascii value of 's'
# define DOUBLE_REDIRECT 100 // ascii value of 'd'

typedef struct s_loc
{
	char			**decon_cmd;
	t_token			*tokens;
	struct s_loc	*next;
}	t_loc;

typedef struct s_idx
{
	int	end_index;
	int	current_end;
	int	start_index;
	int	current_start;
}	t_idx;

t_loc	*ft_parsing(char *src);
int		ft_has_pipe(char *src);
int		ft_arraylen(char **src);
char	*ft_quote_op(char *cmd);
int		ft_has_quotes(char *src);
t_token	ft_redirect_op(char *cmd);
int		ft_invalid_pipe(char *cmd);
int		ft_has_redirect(char *src);
void	*ft_clear_array(char **src);
void	ft_check_here_doc(char *src);
int		ft_redirect_index(char *src);
int		ft_at_index(char *src, char c);
int		ft_redirect_rev_index(char *src);
t_idx	ft_quotes_delimitation(char *src);
void	ft_purge(char **decon, char *src);
void	ft_pipe_op(char *cmd, t_loc *list);
int		ft_at_rev_index(char *src, char c);
char	*ft_get_file(char *cmd, char mode);
char	**ft_arrayjoin(char **src, char *s);
void	ft_add_loc(t_loc **list, char **cmd);
int		ft_input(char *src, int start_index);
int		ft_output(char *src, int start_index);
int		ft_is_not_in_quotes(char *src, char c);
char	*ft_strslice(char *src, int start, int end);
char	**ft_cmd_deconstruct(char *cmd, t_loc *list);
void	ft_file_op(char *path, t_token *tokens, char redirect, char duplicity);

#endif

/*
 * checker les tokens errors sur les quotes non-fermées
 */
