/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:37:23 by brheaume          #+#    #+#             */
/*   Updated: 2023/10/16 14:37:24 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_sig_handle(int signal)
{
	t_mshell	*shell;

	(void)signal;
	shell = ft_return_ptr(NULL, SYS);
	if (shell && !shell->re_draw)
	{
		shell->pec = 1;
		ft_putendl_fd("\0", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	ft_child_sig_handle(int signal)
{
	if (signal == SIGQUIT)
	{
		ft_putendl_fd("\0", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	else if (signal == SIGINT)
	{
		ft_putendl_fd("\0", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

static void	ft_doc_sig_handle(int signal)
{
	short	(*ft)(void);
	char	**s;

	(void)signal;
	s = NULL;
	ft_putendl_fd("\0", 1);
	s = ft_return_ptr(NULL, DOC_FILE);
	ft_free(*s);
	ft = ft_return_ptr(NULL, CLEAN);
	ft();
	exit(130);
}

void	ft_signal_handler(int mode)
{
	if (mode == CMD)
	{
		signal(SIGINT, &ft_sig_handle);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == CHILD)
	{
		signal(SIGINT, &ft_child_sig_handle);
		signal(SIGQUIT, &ft_child_sig_handle);
	}
	else if (mode == HERE_DOC)
	{
		signal(SIGINT, &ft_doc_sig_handle);
		signal(SIGQUIT, SIG_IGN);
	}
}
