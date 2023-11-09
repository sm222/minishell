#include "edit.h"

int	edit_update(void)
{
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (shell)
	{
		if (shell->s_in)
			shell->s_in = ft_free(shell->s_in);
		shell->s_in = ft_strdup("git ls-remote https://github.com/sm222/minishell > file ; diff .git/ORIG_HEAD file ; rm file");
	}
	return (0);
}
