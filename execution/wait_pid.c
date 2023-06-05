
#include "execution.h"

/// @brief run a waitpid on a list of pid_t
/// @param in linklist waitp
/// @param free_f free the list or not
/// @return SUCCESS
short	wait_pids(t_waitp *in, short free_f)
{
	t_waitp *tmp;

	tmp = NULL;
	if (!in)
		return (BAD_ARGS);
	while (in)
	{
		tmp = in->next;
		waitpid(in->pid, NULL, 0);
		if (free_f)
			ft_free(in);
		in = tmp;
	}
	return (SUCCESS);
}

static t_waitp *wait_make_node(pid_t pid)
{
	t_waitp	*new;

	new = ft_calloc(1, sizeof(t_waitp));
	if (!new)
		return (NULL);
	new->pid = pid;
	return (new);
}

/// @brief add a pid to a list 
/// @param in link list
/// @param pid pid to add to the list
/// @return 
int	wait_make_node_last(t_waitp **in, pid_t pid)
{
	t_waitp	*tmp;
	int		len;

	len = 0;
	tmp = NULL;
	if (!in)
		return (BAD_ARGS);
	tmp = (*in);
	if (!tmp)
	{
		(*in) = wait_make_node(pid);
		if (!*in)
			return (M_FAIL);
		return (SUCCESS);
	}
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	tmp->next = wait_make_node(pid);
	if (!tmp->next)
		return (M_FAIL);
	return (SUCCESS + len);
}
