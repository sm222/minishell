#include "execution.h"

/// @brief	use to free data of the shell
/// @param	shell	t_mshell*
void	free_t_mshell(t_mshell *shell)
{
	ft_free(shell->info);
	ft_free(shell->s);
	ft_free(shell->tmp);
	ft_double_sfree((void **)shell->path);
	ft_double_sfree((void **)shell->en);
	ft_return_ptr(NULL, -1);
}

/// @brief	chnage the argv[0] in the t_cmd for the last pec
/// @param	pec	process exit code
/// @param	in	t_cmd* input
void	change_name(int pec, t_cmd *in)
{
	char	*s;

	s = ft_itoa(pec);
	if (s)
	{
		free(in->command[0]);
		in->command[0] = s;
	}
}

/// @brief	chnage the argv for the env
/// @param	in	t_cmd input
/// @return	err code
short	change_av_for_en(t_cmd *in)
{
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (!in || !shell)
		return (BAD_ARGS);
	if (ft_strlen_double(in->command) == 1)
	{
		ft_double_sfree((void **)in->command);
		in->command = ft_cpy_double_char(shell->en);
		if (!in->command)
			return (M_FAIL);
	}
	else
	{
		ft_double_sfree((void **)in->command);
		in->command = NULL;
	}
	return (SUCCESS);
}