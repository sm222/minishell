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
# define PASSED_PREFIX 28
# define PASSED_SUFFIX 31
# define PASSED_THROUGH 29
# define SINGLE_REDIRECT 's'
# define DOUBLE_REDIRECT 'd'

typedef struct s_heap
{
	char 			**cmd;
	t_token			*tokens;
	struct s_heap	*next;
}	t_heap;

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
t_token	ft_redirect_prefix(char *cmd);
t_token	ft_redirect_suffix(char *cmd);
int		ft_list_count(t_decon *head);
int		ft_at_index(char *src, char c);
t_decon	*ft_cmd_deconstruct(char *cmd);
int		ft_at_rev_index(char *src, char c);
char	*ft_get_file(char *cmd, char mode);
char	**ft_cmd_reconstruct(t_decon *decon);
void	ft_add_slice(char *src, t_decon **decon);
char	*ft_strslice(char *src, int start, int end);
int		ft_file_op(char *cmd, char redirect, char mode);

#endif

/* 
 * PASSED_THROUGH = y'a 2 redirect dans la commande, donc ça entoure la commande
 * PASSED_SUFFIX = y'a 1 redirect dans la commande, à la fin de la commande
 * PASSED_PREFIX = y'a 1 redirect dans la commande, au début de la commande
 *
 *
 * vérifie si la commande a PASSED_PREFIX & PASSED_SUFFIX, si oui, change les 
 * pour PASSED_THROUGH, si non, laisse les.
 */
