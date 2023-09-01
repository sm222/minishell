#include "ls_tester.h"


int	main(void)
{
	int	fd;

	fd = open("/tmp/infile", O_CREAT);
	if (fd < 0)
	{
		perror(RED"/tmp/infile"WHT);
		return (1);
	}
	
}