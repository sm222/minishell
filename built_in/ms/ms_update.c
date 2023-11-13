#include "ms.h"

static int	look_v(t_mshell *data)
{
	int		fd;
	char	*s;
	char	*res;
	int		swi;

	swi = 0;
	s = get_env(data->en, "CONPILE_DIR");
	if (s)
	{
		res = ft_strjoin(s, "/.config/version");
		if (res)
		{
			fd = open(res, O_RDONLY);
			res = ft_free(res);
			s = get_next_line(fd);
			close(fd);
			res = get_env(data->en, "V_MINI");
			ft_printf(2, "%oms: last update %s , shell v %s\n", NULL, s, res);
			if (ft_strncmp(res, s, 5) != 0)
				swi = 1;
			ft_free(s);
		}
	}
	return (swi);
}

int	ms_update(int i)
{
	t_mshell	*shell;
	char		*tmp;

	tmp = NULL;
	shell = ft_return_ptr(NULL, SYS);
	if (shell && i)
	{
		if (shell->s_in)
			shell->s_in = ft_free(shell->s_in);
		ft_printf(NO_PRINT, "%oms -r $CONPILE_DIR/scrips/git_job.ms", &tmp);
		shell->s_in = tmp;
	}
	else if (shell)
	{
		if (shell->s_in)
			shell->s_in = ft_free(shell->s_in);
		if (look_v(shell))
			ft_printf(NO_PRINT, "%oms -r $CONPILE_DIR/scrips/update.ms", &tmp);
		shell->s_in = tmp;
	}
	return (0);
}
