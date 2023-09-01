#include "ls_tester.h"

static short	test_file(void)
{
	short	err;

	err = 0;
	if (access("get_next_line.c", F_OK) != 0)
	{
		ft_printf(2, "%o"RED"missing get_next_line.c\n"WHT, NULL);
		err = 1;
	}
	if (access("get_next_line_utils.c", F_OK) != 0)
	{
		ft_printf(2, "%o"RED"missing get_next_line_utils.c\n"WHT, NULL);
		err = 1;
	}
	if (access("get_next_line.h", F_OK) != 0)
	{
		ft_printf(2, "%o"RED"missing get_next_line.h\n"WHT, NULL);
		err = 1;
	}
	return (err);
}

int	ft_ls_tester(char **av, int re_in, int re_out, char **en)
{
	(void)av;
	(void)re_in;
	(void)re_out;
	(void)en;
	if (test_file())
		return (1);
	return (0);
}

int	main(int ac, char **av, char **en)
{
	(void)ac;
	return (ft_ls_tester(av, 0, 0, en));
}