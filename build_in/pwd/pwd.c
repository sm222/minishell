#include "pwd.h"

int	main(void)
{
	char	*tmp;
	char	*new;

	tmp = getcwd(NULL, 0);
	ft_printf(-1, "%o%s\n", &new, tmp);
	ft_putstr_fd(new, STDOUT_FILENO);
	ft_free(tmp);
	ft_free(new);
	return (0);
}