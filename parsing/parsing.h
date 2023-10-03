#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../include/err.h"
# include "../lib/lib_ft/libft.h"
# include "../include/structure.h"
# include "../readline/readline.h"

# include <stdio.h>

# define NODE 1
# define ERROR -2
# define CORRECT 1
# define INVALID -1 
# define INCORRECT 0
# define CHAR_LIMIT 32 // space is the last char not included
# define FIRST_INDEX 0
# define PASSED_QUOTES 29
# define IGNORE_QUOTES 92 //30
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
	int	current_quote;
	int	current;
}	t_idx;

typedef struct s_rdct
{
	int	input;
	int	output;
	int	fd_doc;
	int	in_succ;
	int out_succ;
	int	last_doc;
} t_rdct;

int		ft_verify(char *src);
void	ft_purge(t_loc *list);
t_loc	*ft_parsing(char *src);
int		ft_has_pipe(char *src);
void	ft_quote_op(char *cmd);
int		ft_arraylen(char **src);
int		ft_has_quotes(char *src);
int		ft_quote_error(char *src);
int		ft_invalid_pipe(char *cmd);
int		ft_has_redirect(char *src);
void	*ft_clear_array(char **src);
int		ft_redirect_index(char *src);
void	ft_pass_through(char **decon);
int		ft_at_index(char *src, char c);
t_loc	*ft_validate_cmds(t_loc *list);
int		ft_redirect_rev_index(char *src);
t_idx	ft_quotes_delimitation(char *src);
int		ft_at_rev_index(char *src, char c);
char	*ft_get_file(char *cmd, char mode);
void	ft_pipe_op(char *cmd, t_loc **list);
char	**ft_arrayjoin(char **src, char *s);
int		ft_is_not_in_quotes(char *src, int i);
int		ft_check_here_doc(char *src, t_rdct *fd);
int		ft_redirect_op(char *cmd, t_token *tokens);
char	*ft_strslice(char *src, int start, int end);
char	*ft_file_extract(char *src, int start_index);
int		ft_here_doc(char *src, int start, t_rdct *fd);
int		ft_check_ignore(char *src, int start, int end);
char	**ft_cmd_deconstruct(char *cmd, t_token *tokens);
void	ft_add_loc(t_loc **list, char **cmd, t_token *tokens);
int		ft_input(char *src, t_token *tokens, int start_index);
int		ft_output(char *src, t_token *tokens, int start_index);
int		ft_file_op(char *path, t_token *tokens, char redirect, char duplicity);

#endif
