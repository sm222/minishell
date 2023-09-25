#include "parsing.h"

int	ft_verify(char *src)
{
	if (ft_invalid_pipe(src))
		return (INCORRECT);
	if (ft_quote_error(src))
	{
		ft_putendl_fd("token error near quote", 2);
		return (INCORRECT);
	}
	return (CORRECT);
}

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
				ft_putendl_fd("token error near '|'", 2);
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
		return (INCORRECT);
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
		return (CORRECT);
	return (INCORRECT);
}
