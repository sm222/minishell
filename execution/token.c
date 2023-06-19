
#include "token.h"

short	read_b_flag(int flag, int byte)
{
	if (byte > 8 || byte < 0)
		return (-1);
	return (flag >> byte & 1);
}

void	toggle_b_flag(int *flag, int pos)
{
	int	i;

	i = 2;
	if (pos < 0 || pos > 7)
		return ;
	while (--pos)
		i *= 2;
	*flag ^= i;
}

void	print_byte(int flag)
{
	int	i;

	i = 8;
	while (i)
	{
		printf("%d", flag >> i & 1);
		i--;
	}
	printf("\n");
}

t_token	*make_token(char build_in, int mode, char *redi_in, char *redi_out)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->mode = mode;
	new->pipe_in = 0;
	new->pipe_out = 0;
	new->build_in = build_in;
	new->redi_in = ft_strdup(redi_in);
	if (!new->redi_in)
		return (ft_free(new));
	new->redi_out = ft_strdup(redi_out);
	if (!new->redi_out)
	{
		ft_free(new->redi_in);
		ft_free(new);
		return (NULL);
	}
	return (new);
}
