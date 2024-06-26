/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:36:07 by brheaume          #+#    #+#             */
/*   Updated: 2024/02/20 13:54:56 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../include/err.h"
# include "../lib/lib_ft/libft.h"
# include "../include/structure.h"
# include "../include/readline/readline.h"
# include "../here_doc/here_doc.h"

# include <stdio.h>
# ifndef SENUT
#  define SENUT "syntax error near unexpected token"
# endif

# define NODE 1

# define ERROR -2
# define CORRECT 1
# define INVALID -1 
# define INCORRECT 0

# define CANCEL 33280
# define SINGLE_REDIRECT 115 // ascii value of 's'
# define DOUBLE_REDIRECT 100 // ascii value of 'd'

# define NO_FILE 1
# define NO_ACCESS 2
# define NO_FILE_IN 3
# define NO_FILE_OUT 4
# define FIRST_INDEX 0

# define PASSED_SINGLE 14
# define PASSED_DOUBLE 15
# define PASSED_QUOTES 29
# define IGNORE_QUOTES 30
# define PASSED_THROUGH 31

typedef struct s_loc
{
	char			*slice;
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
	int	out_succ;
	int	last_doc;
}	t_rdct;

//--------------------------//
//     verify & validate    //
//--------------------------//
int		ft_verify(char *src);
int		ft_set_error_code(int code);
t_loc	*ft_validate_cmds(t_loc *list);

//--------------------------//
//           main           //
//--------------------------//
t_loc	*ft_parsing(char *src);
void	ft_add_node(t_loc **list);
void	ft_set_tokens(t_loc **list, t_token *tokens);
void	ft_set_decon(t_loc **list, char **decon_cmd);

//--------------------------//
//           pipe           //
//--------------------------//
int		ft_has_pipe(char *src);
int		ft_invalid_pipe(char *cmd);
int		ft_pipe_op(char *cmd, t_loc **list);

//--------------------------//
//          quotes          //
//--------------------------//
void	ft_quote_op(char *cmd);
int		ft_has_quotes(char *src);
t_idx	ft_quotes_delimitation(char *src);
int		ft_is_not_in_quotes(char *src, int i);

//--------------------------//
//           array          //
//--------------------------//
int		ft_arraylen(char **src);
void	*ft_clear_array(char **src);
char	**ft_arrayjoin(char **src, char *s);

//--------------------------//
//           utils          //
//--------------------------//
void	ft_purge(t_loc *list);
void	ft_pass_through(char **decon);
int		ft_at_index(char *src, char c);
int		ft_at_rev_index(char *src, char c);
char	*ft_strslice(char *src, int start, int end);

//--------------------------//
//         redirect         //
//--------------------------//
int		ft_has_redirect(char *src);
int		ft_redirect_op(char *cmd, t_token *tokens);
int		ft_input(char *src, t_token *tokens, int start_index);
int		ft_output(char *src, t_token *tokens, int start_index);

//--------------------------//
//           file           //
//--------------------------//
char	*ft_get_file(char *cmd, char mode);
char	*ft_file_extract(char *src, int start_index);
int		ft_file_op(char *path, t_token *tokens, char redirect, char duplicity);

//--------------------------//
//           doc            //
//--------------------------//
int		ft_here_doc(char *src, t_rdct *fd);
int		ft_check_here_doc(char *src, t_idx *i_doc);

//--------------------------//
//         fragment         //
//--------------------------//
void	ft_word_delimiter(char *cmd, t_idx *index);
char	**ft_cmd_deconstruct(char *cmd, t_token *tokens);

//--------------------------//
//           error          //
//--------------------------//
int		ft_error_file(char *path, int mode);

#endif
