#include "ms.h"

static int	how_to_use(void)
{
	ft_printf(2, "%oms: -s \n", NULL);
	ft_printf(2, "%o	"DIRL, NULL);
	ft_printf(2, "%o	C show the color pallet", NULL);
	ft_printf(2, "%o	"COLOR_SYS, NULL);
	ft_printf(2, "%oms: -u \n", NULL);
	ft_printf(2, "%o	use too look for update, not ready yet\n", NULL);
	ft_printf(2, "%oms: -l \n", NULL);
	ft_printf(2, "%o	"LOGIC, NULL);
	ft_printf(2, "%oms: -r \n", NULL);
	ft_printf(2, "%o	"RUN, NULL);
	return (0);
}

static int	bad_arg(char *s)
{
	ft_printf(2, "%o"MS_NAME"\b: ms: %s not valid\n", NULL, s);
	return (1);
}
static int	look_arg(char **av, size_t *i, size_t *j)
{
	*j = 0;
	*i = ft_strlen_double(av);
	if (*i == 1)
	{
		how_to_use();
		return (0);
	}
	return (0);
}

int	ft_ms(char **av, int re_in, int re_out, char **en)
{
	size_t	i;
	size_t	j;
	int		err;

	(void)re_in;
	(void)re_out;
	(void)en;
	err = look_arg(av, &i, &j);
	while (++j < i)
	{
		if (ft_strncmp(av[j], "-s", 3) == 0)
			err += ms_edit(av + j + 1, &j);
		else if (ft_strncmp(av[j], "-u", 3) == 0)
			ms_update();
		else if (ft_strncmp(av[j], "-l", 3) == 0)
			err += ms_logic(av + 2, &j);
		else if (ft_strncmp(av[j], "-r", 3) == 0)
			err += ms_run(av + 2, &j);
		else
			err += bad_arg(av[j]);
	}
	return (err);
}
