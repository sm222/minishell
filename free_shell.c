#include "include/minishell.h"

short static	free_data_shell(t_mshell *shell)
{
	free_here_doc(UNLINK);
	shell->pwd = ft_free(shell->pwd);
	shell->rest = ft_free(shell->rest);
	shell->s = ft_free(shell->s);
	shell->prompt = ft_free(shell->prompt);
	shell->path = (char **)ft_double_sfree((void **)shell->path);
	shell->en = (char **)ft_double_sfree((void **)shell->en);
	return (1);
}
short static	free_data_loc(t_loc *data)
{
	t_loc	*tmp;

	while (data)
	{
		tmp = data->next;
		ft_double_sfree((void **)data->decon_cmd);
		ft_free(data->tokens);
		ft_free(data);
		data = tmp;
	}
	return (2);
}

short	clean_shell(void)
{
	t_mshell	*shell;
	t_loc		**loc;
	short		err;

	err = 0;
	shell = ft_return_ptr(NULL, SYS);
	loc = ft_return_ptr(NULL, PARSE);
	if (shell)
		err += free_data_shell(shell);
	if (*loc)
		err += free_data_loc(*loc);
	return (err);
}
