#ifndef EXECUTION_H
# define EXECUTION_H

# include "../minishell.h"

typedef struct s_cmd
{
	struct s_cmd	*prev;
	struct s_cmd	*next;
	char			**commend;
	int				order;
}	t_cmd;

/*/*//*/*//*/*//*/*//*/*//*/*/
t_cmd	*cmd_make_node(char **cmd, int order);
size_t	cmd_node_len(t_cmd *list);
short	cmd_make_node_last(t_cmd **list, char **cmd, int order);
void	cmd_free(t_cmd *in);
/*/*//*/*//*/*//*/*//*/*//*/*/

#endif // EXECUTION_H