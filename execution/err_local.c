#include "execution.h"

short get_result(int err, char *name, int *f, char *mal)
{
	if (!mal && err == SUCCESS)
	{
		*f = M_FAIL;
		return (err_msg(NO_FREE, FAIL, MS_NAME \
			"Malloc fail : ft_execution_buildin"));
	}
	else if (err == EACCES)
	{
		*f = 126;
		ft_printf(STDERR_FILENO, \
		"%ominishell: %s: Permission denied\n", NULL, name);
		return (FAIL);
	}
	return (SUCCESS);
}
