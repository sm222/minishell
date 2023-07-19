#include "unset.h"

int	main(int ac, char **av, char **en)
{
	char	**en_c;

	(void)ac;
	en_c = ft_cpy_double_char(en);
	if (!en_c)
		return (2);
	ft_return_ptr(en_c, ENV_C);
	ft_unset(av, 0, 1, en_c);
	en_c = ft_return_ptr(NULL, ENV_C);
	for (size_t i = 0; en_c[i]; i++)
	{
		printf("%s\n", en_c[i]);
	}
	
	ft_double_sfree((void **)en_c);
	return (0);
}
