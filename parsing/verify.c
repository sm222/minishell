#include "parsing.h"

int	ft_invalid_pipe(char *cmd)
{
	int	i;

	i = FIRST_INDEX;
	while (cmd[i])
	{
		if (cmd[i] == '|' && cmd[i + 1] == '|')
		{
			if (ft_is_not_in_quotes(cmd, i))
			{
				ft_check_here_doc(cmd);
				printf("printf: do here_doc here\n");
				ft_putendl_fd("token error near '|'\n", 2);
				return (CORRECT);
			}
		}
		i++;
	}
	return (INCORRECT);
}

int	ft_quote_error(char *src)
{
	int		i;
	char	c;
	int		open_mark;

	i = FIRST_INDEX;
	open_mark = INCORRECT;
	if (!src)
		return (INVALID);
	while (src[i])
	{
		if (src[i] == '"' || src[i] == '\'')
		{
			c = src[i++];
			open_mark = CORRECT;
			while (src[i] && src[i] != c)
				i++;
			if (i != (int)ft_strlen(src))
				open_mark = INCORRECT;
		}
		i++;
	}
	if (open_mark)
		return (INCORRECT);
	return (CORRECT);
}
