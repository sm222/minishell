#include "env.h"

int	main(int ac, char **av, char **en)
{
	(void)ac;
	if (ft_strlen_double(av) > 1)
		ft_env(NULL, 0, 1);
	else
		ft_env(en, 0, 1);
	return (0);
}
