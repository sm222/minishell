#include "parsing.h"

static int	ft_quote_error(char *src)
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

static int	ft_redirect_error(char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '<' || src[i] == '>')
		{
			if (i + 2 < (int)ft_strlen(src))
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
	if (ft_quote_error(src))
	{
		ft_putendl_fd(MS_NAME"\b: token error near quote", 2);
		res = INCORRECT;
	}
	if (ft_redirect_error(src))
	{
		ft_putendl_fd(MS_NAME"\b: token error near redirection", 2);
		res = INCORRECT;
	}
	if (res == INCORRECT)
		ft_check_here_doc(src, NULL);
	return (res);
}
