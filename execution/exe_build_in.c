
#include "execution.h"


static char	*find_build_in(char *name)
{
	if (ft_strncmp(name, ECHO, ft_strlen(ECHO) + 1) == 0)
		return (ft_strdup(ECHO_PATH ECHO));
	if (ft_strncmp(name, PWD, ft_strlen(PWD) + 1) == 0)
		return (ft_strdup(PWD_PATH PWD));
	return (NULL);
}

int	ft_execution_buildin(t_cmd *in, t_waitp **wait, int cmd_len)
{
	char	*name;

	name =  find_build_in(in->command[0]);
	ft_free(in->command[0]);
	in->command[0] = name;
	if (cmd_len > 1)
		return(ft_execution(in, wait));
	return (0);
}
