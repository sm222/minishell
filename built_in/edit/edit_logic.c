#include "edit.h"

int	edit_logic(char **av)
{
	t_mshell	*shell;

	(void)av;
	shell = ft_return_ptr(NULL, SYS);
	if (shell)
		ft_printf(2, "%olast err was %d\n", NULL, shell->pec);
	return (0);
}