
#include "execution.h"

static char	*find_build_in(char *name, int *f)
{
	if (f)
	{
		*f = SUCCESS;
		if (ft_strncmp(name, ECHO, ft_strlen(ECHO) + 1) == 0)
			return (ft_strdup(ECHO_PATH "ft_"ECHO));
		if (ft_strncmp(name, PWD, ft_strlen(PWD) + 1) == 0)
			return (ft_strdup(PWD_PATH "ft_"PWD));
		if (ft_strncmp(name, CD, ft_strlen(CD) + 1) == 0)
			return (ft_strdup(CD_PATH "ft_"CD));
		if (ft_strncmp(name, EXIT, ft_strlen(EXIT) + 1) == 0)
			return (ft_strdup(EXIT_PATH "ft_"EXIT));
		*f = FAIL;
		return (NULL);
	}
	*f = BAD_ARGS;
	return (NULL);
}

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
	return (NULL);
}

static	int	run_local(int(*ft)(char **, int, int), t_cmd *in)
{
	int		*err;
	char	*s;

	if (!ft)
		return (FAIL);
	err = ft_return_ptr(NULL, PEC);
	if (ft_strncmp(in->command[0], EXIT, ft_strlen(EXIT) + 1) == 0)
	{
		s = ft_itoa(*err);
		if (s)
		{
			free(in->command[0]);
			in->command[0] = s;
		}
	}
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
