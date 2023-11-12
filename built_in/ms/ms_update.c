#include "ms.h"

int	ms_update(void)
{
	t_mshell	*shell;
	char		*tmp;

	tmp = NULL;
	shell = ft_return_ptr(NULL, SYS);
	if (shell)
	{
		if (shell->s_in)
			shell->s_in = ft_free(shell->s_in);
		ft_printf(NO_PRINT, "%oms -r $CONPILE_DIR/scrips/update.ms", &tmp);
		shell->s_in = tmp;
		ft_printf(2, "%o%s\n", NULL, tmp);
	}
	return (0);
}
