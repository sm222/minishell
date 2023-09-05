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

int	change_env_data(t_mshell *data)
{
	size_t	i;

	i = 0;
	while (data->en && data->en[i])
	{
		if (ft_strncmp("OLDPWD", data->en[i], 6) == 0 && \
		(data->en[i][6] == '=' || data->en[i][6] == 0))
			oldpwd(data);
		if (ft_strncmp("PWD", data->en[i], 3) == 0 && \
		(data->en[i][3] == '=' || data->en[i][3] == 0))
			new_pwd(data);
		i++;
	}
	return (FAIL);
}


/*
char	*edit_str(char *s, size_t i, char **en)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;

}

char	*change_dolar(char *old, char **en)
{
	short	mode;
	char	*new;
	size_t	i;

	i = 0;
	new = NULL;
	mode = 0;
	while (old && old[i])
	{
		if (mode == 0 && (old[i] == '$' && old[i + 1] && old[i + 1] != ' '))
			new = edit_str(old, i, en);
	}
	
}

int	main(int ac, char **av, char **en)
{
	int	i;
	char	*t;

	i = 1;
	while (i < ac)
	{
		t = change_dolar(av[i], en);
		printf("%s\n", t);
		t = ft_free(t);
	}
}
*/