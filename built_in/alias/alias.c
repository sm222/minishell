
#include "alias.h"

static int	set_aliace(char **av)
{
	int	err;

	err = 0;
	
}


int	ft_alias(char **av, int re_in, int re_out, char **en)
{
	int	err;
	size_t	i;
	size_t	len;

	err = 0;
	i = 1;
	len = ft_strlen_double(av);
	while (i < len)
	{
		printf("%s\n", av[i++]);
	}
	(void)re_in;
	(void)re_out;
	(void)en;
	return (err);
}
