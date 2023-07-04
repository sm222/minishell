#include "parsing.h"

int	ft_has_pipe(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '|')
			return (CORRECT);
		i++;
	}
	return (INCORRECT);
}

void	ft_pipe_op(void)
{
	printf("pipe operant\n");
}
