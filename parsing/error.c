#include "parsing.h"

int	ft_error_file(char *path, int mode)
{
	if (mode == NO_FILE_OUT)
		ft_printf(2, MS_NAME"\b: no file given for output redirection\n");
	else if (mode == NO_ACCESS)
		ft_printf(2, MS_NAME"\b: %s: can't access file\n", path);
	else if (mode == NO_FILE)
		ft_printf(2, MS_NAME"\b: %s: no such file or directory\n", path);
	else if (mode == NO_FILE_IN)
		ft_printf(2, MS_NAME"\b: no file given for input redirection\n");
	ft_set_error_code(1);
	return (INCORRECT);
}
