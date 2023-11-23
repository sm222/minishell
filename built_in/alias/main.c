
#include "alias.h"

int	main(int ac, char **av, char **en)
{
	int	err;

	(void)ac;
	(void)en;
	err = ft_alias(av, 0, 1, en);
	return (err);
}