/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:50 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/16 14:24:50 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

/// @brief	use to free data of the shell
/// @param	shell	t_mshell*
void	free_t_mshell(t_mshell *shell)
{
	shell->s       = ft_free(shell->s);
	shell->pwd     = ft_free(shell->pwd);
	shell->rest    = ft_free(shell->rest);
	shell->prompt  = ft_free(shell->prompt);
	shell->termios = ft_free(shell->termios);
	shell->en      = (char **)ft_double_sfree((void **)shell->en);
	shell->path    = (char **)ft_double_sfree((void **)shell->path);
	shell->alias   = (char **)ft_double_sfree((void **)shell->alias);
	ft_return_ptr(NULL, -1);
}

/// @brief	chnage the argv[0] in the t_cmd for the last pec
/// @param	pec	process exit code
/// @param	in	t_cmd* input
void	change_name(int pec, t_cmd *in)
{
	char	*s;

	if (in)
	{
		s = ft_itoa(pec);
		if (s)
		{
			free(in->command[0]);
			in->command[0] = s;
		}
	}
}

short	change_av_pwd(t_cmd *in, char *pwd)
{
	char	*tmp;

	if (!in || !pwd)
		return (BAD_ARGS);
	tmp = ft_strdup(pwd);
	if (tmp)
	{
		ft_free(in->command[0]);
		in->command[0] = tmp;
		return (SUCCESS);
	}
	return (M_FAIL);
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

int	change_env_data(t_mshell *data, char *old_pwd)
{
	size_t	i;

	i = 0;
	while (data->en && data->en[i])
	{
		if (ft_strncmp("OLDPWD", data->en[i], 6) == 0 && \
		(data->en[i][6] == '=' || data->en[i][6] == 0))
			oldpwd(data, old_pwd);
		if (ft_strncmp("PWD", data->en[i], 3) == 0 && \
		(data->en[i][3] == '=' || data->en[i][3] == 0))
			new_pwd(data);
		i++;
	}
	return (FAIL);
}
