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

static	void	get_user(t_mshell *shell)
{
	char	*logname;

	logname = NULL;
	logname = get_env(shell->en, "LOGNAME");
	shell->pwd = get_path(getcwd(NULL, 0), shell->pwd);
	if (logname)
		ft_printf(NO_PRINT, "%o"GRN"%s"WHT"[%s]$ ", &shell->prompt, \
	shell->pwd, logname);
	else
		ft_printf(NO_PRINT, "%o"GRN"%s "WHT"$ ", &shell->prompt, shell->pwd);
}

static short	ft_caller(t_mshell *shell)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < ft_strlen(shell->s))
	{
		shell->cmd_list = NULL;
		i = 0;
		while (shell->s[i + j] && shell->s[i + j] != '&')
			i++;
		shell->rest = ft_strndup(shell->s + j, i);
		j += i + 1;
		if (!shell->rest)
			break ;
		converter(shell->rest, &shell->cmd_list);
		run_cmd(shell->cmd_list, shell);
		free_here_doc(UNLINK);
		shell->rest = ft_free(shell->rest);
	}
	return (SUCCESS);
}

short	reset_data_main(t_mshell *shell)
{
	shell->s = ft_free(shell->s);
	shell->prompt = ft_free(shell->prompt);
	get_user(shell);
	shell->cmd_list = NULL;
	shell->s = readline(shell->prompt);
	if (!shell->s)
		return (FAIL);
	else if (shell->s[0])
		add_history(shell->s);
	ft_change_dolar(&shell->s, shell->en, 0, shell->pec);
	ft_caller(shell);
	return (SUCCESS);
}
