#include "pwd.h"

/// @brief	
/// @param	av		argv
/// @param	re_in	redirect in
/// @param	re_out	redirect out
/// @return 2 if fail, else err code
int	ft_pwd(char **av, int re_in, int re_out, char **en)
{
	char	*tmp;
	char	*new;

	(void)re_in;
	(void)en;
	if (ft_strlen_double(av) > 1)
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
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
