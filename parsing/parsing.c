#include "parsing.h"

int	ft_parsing(char *src)
{
	if (ft_verify(src))
	{
		if (ft_has_pipe(src))
			ft_pipe_op();
		if (ft_has_redirect(src))
			ft_redirect_op();
	}
	else
		return (INCORRECT);
	return (CORRECT);
}
