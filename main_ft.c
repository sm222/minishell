#include "include/minishell.h"

static char	*get_path(char *new, char *old)
{
	if (!new && old)
		return (old);
	else if (new && old)
	{
		ft_free(old);
		return (new);
	}
	else if (!new && !old)
		return (ft_strdup("?"));
	else if (new && !old)
		return (new);
	return (NULL);
}

short	reset_data_main(t_mshell *shell)
{
	shell->s = ft_free(shell->s);
	shell->tmp = ft_free(shell->tmp);
	shell->info = get_path(getcwd(NULL, 0), shell->info);
	if (get_env(shell->en, "LOGNAME"))
		ft_printf(NO_PRINT, "%o"GRN"%s"WHT"[%s]$ ", &shell->tmp, \
	shell->info, get_env(shell->en, "LOGNAME"));
	else
		ft_printf(NO_PRINT, "%o"GRN"%s "WHT"$ ", &shell->tmp, shell->info);
	shell->cmd_list = NULL;
	shell->s = readline(shell->tmp);
	if (!shell->s || !shell->s[0])
		return (FAIL);
	else
		add_history(shell->s);
	change_dolar(&shell->s, shell->en, 0, shell->pec);
	return (SUCCESS);
}
