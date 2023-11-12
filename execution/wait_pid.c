/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:26:42 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/12 13:13:23 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	get_err_code(int pec, int l)
{
	unsigned char	r_val;

	r_val = pec;
	if (l > 0)
	{
		if (WIFEXITED(pec))
			r_val = WEXITSTATUS(pec);
		else if (WIFSIGNALED(pec))
			r_val = (128 + WTERMSIG(pec));
	}
	return (r_val);
}

// do later
// SIGSTOP
// SIGTSTP

static void	err_list2(char *name, int r_val)
{
	if (r_val == 142)
		ft_printf(2, "%o%s\b: alarm %s\n", NULL, MS_NAME, name);
	if (r_val == 152)
		ft_printf(2, "%o%s\b: cpu limit exceeded %s\n", NULL, MS_NAME, name);
	if (r_val == 153)
		ft_printf(2, "%o%s\b: file size limit exceeded %s\n", NULL, MS_NAME, name);
	if (r_val == 154)
		ft_printf(2, "%o%s\b: virtual time alarm %s\n", NULL, MS_NAME, name);
	if (r_val == 155)
		ft_printf(2, "%o%s\b: profile signal %s\n", NULL, MS_NAME, name);
	if (r_val == 141)
		ft_printf(2, "%o%s\b: sigpipe you litte pbergero %s\n", NULL, MS_NAME, name);
	if (r_val == 132)
		ft_printf(2, "%o%s\b: illegal hardware instruction %s\n", NULL, MS_NAME, name);
	if (r_val == 158 || r_val == 159)
		ft_printf(2, "%o%s\b: user-defined signal %d %s\n", NULL, MS_NAME, r_val - 157, name);
	if (r_val == 129)
		ft_printf(2, "%o%s\b: hangup %s\n", NULL, MS_NAME, name);
}
static void	print_err(char *name, int pec)
{
	int	r_val;

	r_val = 0;
	if (pec)
	{
		if (WIFEXITED(pec))
			r_val = WEXITSTATUS(pec);
		else if (WIFSIGNALED(pec))
			r_val = (128 + WTERMSIG(pec));
	}
	if (r_val == 133)
		ft_printf(2, "%o%s\b: trace trap %s\n", NULL, MS_NAME, name);
	if (r_val == 139)
		ft_printf(2, "%o%s\b: segmentation fault %s\n", NULL, MS_NAME, name);
	if (r_val == 134)
		ft_printf(2, "%o%s\b: abort %s\n", NULL, MS_NAME, name);
	if (r_val == 143)
		ft_printf(2, "%o%s\b: terminated %s\n", NULL, MS_NAME, name);
	if (r_val == 138)
		ft_printf(2, "%o%s\b: bus error %s\n", NULL, MS_NAME, name);
	if (r_val == 136)
		ft_printf(2, "%o%s\b: floating point exception %s\n", NULL, MS_NAME, name);
	err_list2(name, r_val);
	ft_free(name);
}
//136

/// @brief	run a waitpid on a list of pid_t
/// @param	in	linklist waitp
/// @param	free_f	free the list or not
/// @return	SUCCESS, BAD_ARGS
short	wait_pids(t_waitp *in, short free_f)
{
	t_waitp	*tmp;
	int		pec;
	int		*new_pec;
	int		last;

	tmp = NULL;
	last = 0;
	if (!in)
		return (BAD_ARGS);
	while (in)
	{
		tmp = in->next;
		if (in->pid >= 0)
			waitpid(in->pid, &pec, 0);
		else
			pec = in->built;
		last = in->pid;
		print_err(in->name, pec);
		if (free_f)
			ft_free(in);
		in = tmp;
	}
	new_pec = ft_return_ptr(NULL, PEC);
	*new_pec = get_err_code(pec, last);
	return (SUCCESS);
}

/// @brief	make new node
/// @param	pid	new pid
/// @return	new node
static t_waitp	*wait_make_node(pid_t pid, int local, char *name)
{
	t_waitp	*new;

	new = ft_calloc(1, sizeof(t_waitp));
	if (!new)
		return (NULL);
	new->pid = pid;
	new->built = local;
	new->name = name;
	return (new);
}

/// @brief	add a pid to a list 
/// @param	in	link list
/// @param	pid	pid to add to the list
/// @return	SUCCESS + len
/// @return	BAD_ARGS if miss some argument
/// @return	M_FAIL if malloc fail
int	wait_make_node_last(t_waitp **in, pid_t pid, int flag, char *name)
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
		(*in) = wait_make_node(pid, flag, name);
		if (!*in)
			return (M_FAIL);
		return (SUCCESS);
	}
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	tmp->next = wait_make_node(pid, flag, name);
	if (!tmp->next)
		return (M_FAIL);
	return (SUCCESS + len);
}
