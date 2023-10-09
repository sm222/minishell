#include "../include/minishell.h"

static void	ft_sig_handle(int signal)
{
	(void)signal;
	ft_putendl_fd("\0", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
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

	(void)signal;
	ft_putendl_fd("\0", 1);
	
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
