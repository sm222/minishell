#include "execution.h"

short	oldpwd(t_mshell *data)
{
	char	*new;
	char	**spl;

	ft_printf(NO_PRINT, "%oex OLDPWD=%s", &new, data->info);
	spl = ft_split(new, ' ');
	ft_export(spl, 0, 1, data->en);
	ft_double_sfree((void **)spl);
	ft_free(new);
	return (SUCCESS);
}

short	new_pwd(t_mshell *data)
{
	char	*new;
	char	**spl;

	ft_printf(NO_PRINT, "%oex PWD=%s", &new, getcwd(NULL, 0));
	spl = ft_split(new, ' ');
	ft_export(spl, 0, 1, data->en);
	ft_double_sfree((void **)spl);
	ft_free(new);
	return (SUCCESS);
}
