#include "parsing.h"

int	ft_has_redirect(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '>' || src[i] == '<')
			return (CORRECT);
		i++;
	}
	return (INCORRECT);
}

void	ft_redirect_op(void)
{
	printf("redirect operant\n")
}
