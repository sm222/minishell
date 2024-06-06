/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:26:42 by anboisve          #+#    #+#             */
/*   Updated: 2024/05/19 13:23:53 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "sig_list.h"

static int	get_err_code(int pec, int local)
{
	if (local > 0)
	{
		if (WIFEXITED(pec))
			return ((unsigned char)WEXITSTATUS(pec));
		else if (WIFSIGNALED(pec))
			return((unsigned char)(128 + WTERMSIG(pec)));
	}
	return ((unsigned char)pec);
}

// do later
// SIGSTOP
// SIGTSTP

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
	//!shoud show  minishell : ./a.out segmentation fault
	if (r_val == 141 || r_val == 130 || r_val == 131)
		;
	else if (r_val >= 129 && r_val <= 155)
		ft_printf(2, "%o%s\b: %s %s\n", NULL, MS_NAME, \
		signal_list[r_val - SIGOFSET] + 4, name);
	else if (r_val == 158 || r_val == 159)
		ft_printf(2, "%o%s\b: user-defined signal %d %s\n", NULL, \
		MS_NAME, r_val - 157, name);
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
