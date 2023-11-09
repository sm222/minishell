#include "edit.h"

int	edit_logic(char **av, size_t *j)
{
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (shell)
	{
		*j += ft_strlen_double(av);
		if (av[0] && av[1])
		{
			shell->s_in = ft_free(shell->s_in);
			if (!shell->pec)
				shell->s_in = ft_strdup(av[0]);
			else
				shell->s_in = ft_strdup(av[1]);
			return (0);
		}
		else
			ft_printf(2, "%o"MS_NAME"\b: edit: "LOGIC, NULL);
		return (1);
	}
	return (0);
}
