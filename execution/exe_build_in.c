
#include "execution.h"

static char	*find_build_in(char *name)
{
	if (ft_strncmp(name, ECHO, ft_strlen(ECHO) + 1) == 0)
		return (ft_strdup(ECHO_PATH "ft_"ECHO));
	if (ft_strncmp(name, PWD, ft_strlen(PWD) + 1) == 0)
		return (ft_strdup(PWD_PATH "ft_"PWD));
	if (ft_strncmp(name, CD, ft_strlen(CD) + 1) == 0)
		return (ft_strdup(CD_PATH "ft_"CD));
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
	return (NULL);
}

static	int	run_local(int(*ft)(char **, int , int), t_cmd *in)
{
	int	*err;
	
	if (!ft)
		return (FAIL);
	err = fr_return_ptr(NULL, PEC);
	*err = ft(in->command, in->tok->redi_in, in->tok->redi_out);
	return (SUCCESS);
}

int	ft_execution_buildin(t_cmd *in, t_waitp **wait, int cmd_len)
{
	char	*name;

	if (cmd_len > 1)
	{
		name = find_build_in(in->command[0]);
		if (!name)
			return (M_FAIL);
		ft_free(in->command[0]);
		in->command[0] = name;
		return(ft_execution(in, wait));
	}
	else if (cmd_len == 1)
		return (run_local(find_build_in_l(in->command[0]), in));
	return (FAIL);
}
