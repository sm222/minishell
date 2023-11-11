#include "ms.h"

int	ms_update(void)
{
	t_mshell	*shell;
	char		*tmp;
	char		pwd[PATH_MAX];

	tmp = NULL;
	shell = ft_return_ptr(NULL, SYS);
	if (shell)
	{
		getcwd(pwd, PATH_MAX);
		if (shell->s_in)
			shell->s_in = ft_free(shell->s_in);
		ft_printf(NO_PRINT, "%ocd %s && pwd && sleep 2 && make && cd %s", &tmp, shell->compile_dir, pwd);
		shell->s_in = tmp;
		ft_printf(2, "%o%s\n", NULL, tmp);
	}
	return (0);
}
