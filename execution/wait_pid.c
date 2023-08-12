
#include "execution.h"

static int	get_err_code(int pec, short l)
{
	int	new_pec;

	if (l == FALSE)
	{
		new_pec = 0;
		if (WIFEXITED(pec))
			new_pec = WEXITSTATUS(pec);
		else if (WIFSIGNALED(pec))
			new_pec = (128 + WTERMSIG(pec));
		return (new_pec);
	}
	return (pec);
}

/// @brief	run a waitpid on a list of pid_t
/// @param	in	linklist waitp
/// @param	free_f	free the list or not
/// @return	SUCCESS, BAD_ARGS
short	wait_pids(t_waitp *in, short free_f)
{
	t_waitp	*tmp;
	int		*pec;
	int		last;

	tmp = NULL;
	if (!in)
		return (BAD_ARGS);
	pec = ft_return_ptr(NULL, PEC);
	while (in)
	{
		tmp = in->next;
		last = in->built;
		debug(in->pid, "pid", FILE_DEF);
		waitpid(in->pid, pec, 0);
		if (free_f)
			ft_free(in);
		in = tmp;
	}
	debug(*pec, "wait_pid", FILE_DEF);
	if (last == FALSE)
	{
		*pec = get_err_code(*pec, last);
		debug(*pec, "wait_pid if", FILE_DEF);
	}
	debug(*pec, "wait_pid2", FILE_DEF);
	return (SUCCESS);
}

/// @brief	make new node
/// @param	pid	new pid
/// @return	new node
static t_waitp	*wait_make_node(pid_t pid, int local)
{
	t_waitp	*new;

	new = ft_calloc(1, sizeof(t_waitp));
	if (!new)
		return (NULL);
	new->pid = pid;
	new->built = local;
	return (new);
}

/// @brief	add a pid to a list 
/// @param	in	link list
/// @param	pid	pid to add to the list
/// @return	SUCCESS + len
/// @return	BAD_ARGS if miss some argument
/// @return	M_FAIL if malloc fail
int	wait_make_node_last(t_waitp **in, pid_t pid, int l)
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
		(*in) = wait_make_node(pid, l);
		if (!*in)
			return (M_FAIL);
		return (SUCCESS);
	}
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	tmp->next = wait_make_node(pid, l);
	if (!tmp->next)
		return (M_FAIL);
	return (SUCCESS + len);
}
