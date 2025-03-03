
#include "execution.h"

short	oldpwd(t_mshell *data, char *old_pwd)
{
	char	*new;
	char	**spl;

	ft_printf(NO_PRINT, "%oex\bOLDPWD=%s", &new, old_pwd);
	spl = ft_split(new, '\b');
	ft_export(spl, 0, 1, data->en);
	ft_double_sfree((void **)spl);
	ft_free(new);
	return (SUCCESS);
}

short	new_pwd(t_mshell *data)
{
	char	*new;
	char	**spl;
	char	pwd[PATH_MAX + 1];

	ft_bzero(pwd, PATH_MAX + 1);
	getcwd(pwd, PATH_MAX);
	if (pwd[0])
	{
		ft_printf(NO_PRINT, "%oex\bPWD=%s", &new, pwd);
		spl = ft_split(new, '\b');
		ft_export(spl, 0, 1, data->en);
		ft_double_sfree((void **)spl);
		ft_free(new);
	}
	return (SUCCESS);
}
