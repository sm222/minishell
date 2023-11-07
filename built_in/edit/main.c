
#include "edit.h"

int	main(int ac, char **av, char **en)
{
	char	**en_c;
	int		err;

	(void)ac;
	en_c = ft_cpy_double_char(en);
	ft_return_ptr(en_c, ENV_C);
	if (!en_c)
		return (2);
	err = ft_edit(av, 0, 1, en_c);
	ft_double_sfree((void **)ft_return_ptr(NULL, ENV_C));
	return (err);
}
