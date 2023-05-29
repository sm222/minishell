
#ifndef EXECUTION_H
# define EXECUTION_H

# include "../lib/lib_ft/libft.h"
# include "../include/err.h"

typedef struct s_cmd
{
	struct s_cmd	*prev;
	struct s_cmd	*next;
	char			**command;
	int				order;
	int				pipe[2];
	char			mode;
}	t_cmd;

/*/*//*/*//*/*//*/*//*/*//*/*/
void	cmd_free(t_cmd *in);
size_t	cmd_node_len(t_cmd *list);
t_cmd	*cmd_make_node(char **cmd, int order);
short	cmd_make_node_last(t_cmd **list, char **cmd, int order);
/*/*//*/*//*/*//*/*//*/*//*/*/

#endif // EXECUTION_H