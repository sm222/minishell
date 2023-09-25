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
	char	*logname;

	logname = NULL;
	shell->s = ft_free(shell->s);
	shell->prompt = ft_free(shell->prompt);
	shell->pwd = get_path(getcwd(NULL, 0), shell->pwd);
	logname = get_env(shell->en, "LOGNAME");
	if (logname)
		ft_printf(NO_PRINT, "%o"GRN"%s"WHT"[%s]$ ", &shell->prompt, \
	shell->pwd, logname);
	else
		ft_printf(NO_PRINT, "%o"GRN"%s "WHT"$ ", &shell->prompt, shell->pwd);
	shell->cmd_list = NULL;
	shell->s = readline(shell->prompt);
	if (!shell->s || !shell->s[0])
		return (FAIL);
	else
		add_history(shell->s);
	ft_change_dolar(&shell->s, shell->en, 0, shell->pec);
	converter(shell->s, &shell->cmd_list);
	return (SUCCESS);
}
