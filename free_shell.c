#include "include/minishell.h"

short static	free_data_shell(t_mshell *data)
{
	data->s
}

short	clean_shell(void(*f) (void *), void *data)
{
	if (!f)
		return (BAD_ARGS);
	f(data);
}