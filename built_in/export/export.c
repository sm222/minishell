
#include "export.h"

void	print_env(char **en, int re_out)
{
	size_t	i;

	i = 0;
	while (en && en[i])
		ft_printf(re_out, "%odeclare -x %s\n", NULL ,en[i++]);
}

int	ft_export(char **av, int re_in, int re_out, char **en)
{
	(void)re_in;
	if (ft_strlen_double(av) == 1)
		print_env(en, re_out);
	return (EXIT_SUCCESS);
}