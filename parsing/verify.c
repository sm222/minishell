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

int	ft_redirect_error(char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '<' || src[i] == '>')
		{
			if (src[i + 2] == '<' || src[i + 2] == '>')
				return (CORRECT);
		}
		i++;
	}
	return (INCORRECT);
}

int	ft_verify(char *src)
{
	int	res;

	res = CORRECT;
	if (ft_invalid_pipe(src))
		res = INCORRECT;
	if (ft_quote_error(src))
	{
		ft_putendl_fd("token error near quote", 2);
		res = INCORRECT;
	}
	if (ft_redirect_error(src))
	{
		ft_putendl_fd("token error near redirection", 2);
		res = INCORRECT;
	}
	if (res == INCORRECT)
		ft_check_here_doc(src);
	return (res);
}
