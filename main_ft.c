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
	short	type;

	j = 0;
	ft_set_mode(-1);
	while (j < ft_strlen(shell->s))
	{
		shell->cmd_list = NULL;
		i = look_for_type(shell->s + j, &type);
		if (type == -1)
			return (FAIL);
		shell->rest = ft_strndup(shell->s + j, i);
		if (!shell->rest)
			break ;
		j += i + 2;
		converter(shell->rest, &shell->cmd_list);
		run_cmd(shell->cmd_list, shell);
		free_here_doc(UNLINK);
		shell->rest = ft_free(shell->rest);
		if ((shell->pec != 0 && type == '&') || \
			(shell->pec == 0 && type == '|'))
			break ;
	}
	return (SUCCESS);
}

short	reset_data_main(t_mshell *shell)
{
	shell->s = ft_free(shell->s);
	shell->prompt = ft_free(shell->prompt);
	get_user(shell);
	shell->s = readline(shell->prompt);
	if (!shell->s)
		return (FAIL - 1);
	else if (shell->s[0])
		add_history(shell->s);
	ft_change_dolar(&shell->s, shell->en, 0, shell->pec);
	return (ft_caller(shell));
}
