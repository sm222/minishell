
#include "execution.h"

/// @brief 			try to find the cmd adrres
/// @param name		name of the cmd
/// @param f		flag
/// @return 
static char	*find_build_in(char *name, int *f)
{
	if (f && name)
	{
		*f = SUCCESS;
		if (ft_strncmp(name, ECHO, ft_strlen(ECHO) + 1) == 0)
			return (ft_strdup(ECHO_PATH "ft_"ECHO));
		if (ft_strncmp(name, PWD, ft_strlen(PWD) + 1) == 0)
			return (ft_strdup(PWD_PATH "ft_"PWD));
		if (ft_strncmp(name, CD, ft_strlen(CD) + 1) == 0)
			return (ft_strdup(CD_PATH "ft_"CD));
		if (ft_strncmp(name, ENV, ft_strlen(EXIT) + 1) == 0)
			return (ft_strdup(ENV_PATH "ft_"ENV));
		if (ft_strncmp(name, EXIT, ft_strlen(EXIT) + 1) == 0)
			return (ft_strdup(EXIT_PATH "ft_"EXIT));
		*f = FAIL;
		return (NULL);
	}
	else if (f)
		*f = BAD_ARGS;
	return (NULL);
}

/// @brief return the addres of the built in
/// @param name	char* name of the cmd you look for
/// @return	void* of the ft
static void	*find_build_in_l(char *name)
{
	if (ft_strncmp(name, ECHO, ft_strlen(ECHO) + 1) == 0)
		return (&ft_echo);
	if (ft_strncmp(name, PWD, ft_strlen(PWD) + 1) == 0)
		return (&ft_pwd);
	if (ft_strncmp(name, CD, ft_strlen(CD) + 1) == 0)
		return (&ft_cd);
	if (ft_strncmp(name, EXIT, ft_strlen(EXIT) + 1) == 0)
		return (&ft_exit);
	if (ft_strncmp(name, ENV, ft_strlen(ENV) + 1) == 0)
		return (&ft_env);
	return (NULL);
}

/// @brief 
/// @param in 
/// @param local 
static void	change_arg(t_cmd *in, short local)
{
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (ft_strncmp(in->command[0], EXIT, ft_strlen(EXIT) + 1) == 0)
	{
		change_name(shell->pec, in);
		if (local)
		{
			free_t_mshell(shell);
			cmd_free(&in);
			exit(shell->pec);
		}
	}
	if (ft_strncmp(in->command[0], ENV, ft_strlen(ENV) + 1) == 0)
		if (change_av_for_en(in) < SUCCESS)
			err_msg(PERROR, M_FAIL, "change_av_for_en");
}

/// @brief 
/// @param ft 
/// @param in 
/// @return 
static	int	run_local(int(*ft)(char **, int, int), t_cmd *in)
{
	int		*err;

	err = ft_return_ptr(NULL, PEC);
	if (!ft)
		return (FAIL);
	change_arg(in, TRUE);
	*err = ft(in->command, in->tok->redi_in, in->tok->redi_out);
	return (SUCCESS);
}

/// @brief take a cmd and redirect it to a buildin, if can't find it try to run a bash one
/// @param in 
/// @param wait 
/// @param cmd_len 
/// @return 
int	ft_execution_buildin(t_cmd *in, t_waitp **wait, int cmd_len)
{
	int		f;
	char	*name;

	name = NULL;
	if (cmd_len > 1)
	{
		name = find_build_in(in->command[0], &f);
		if (!name && f == SUCCESS)
			return (err_msg(NO_FREE, M_FAIL, MS_NAME "Malloc fail : ft_execution_buildin"));
		if (f != FAIL)
		{
			ft_free(in->command[0]);
			in->command[0] = name;
		}
		change_arg(in, FALSE);
		return(ft_execution(in, wait));
	}
	else if (cmd_len == 1)
	{
		if (run_local(find_build_in_l(in->command[0]), in) == FAIL)
			return(ft_execution(in, wait));
		return (SUCCESS);
	}
	return (FAIL);
}
