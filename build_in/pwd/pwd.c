#include "pwd.h"

int	ft_pwd(char **av, int re_in, int re_out)
{
	char	*tmp;
	char	*new;

	(void)re_in;
	if (ft_strlen_double(av) > 1)
	{
		ft_putstr_fd("pwd: too many arguments\n",2);
		return (EXIT_FAILURE);
	}
	if (re_out < 0)
		re_out = STDOUT_FILENO;
	tmp = getcwd(NULL, 0);
	if (!tmp)
		return (EX_SOFTWARE);
	ft_printf(-1, "%o%s\n", &new, tmp);
	if (!new)
	{
		ft_free(tmp);
		return (EX_SOFTWARE);
	}
	ft_putstr_fd(new, re_out);
	ft_free(tmp);
	ft_free(new);
	return (EXIT_SUCCESS);
}
