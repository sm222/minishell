
#include "cd.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
		chdir("~");
	return (0);
}