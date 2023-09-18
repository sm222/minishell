#include "todo.h"

int	ft_is_not_in_quotes(char *src, int index)
{
	int	i;
	int	not_in_quote;

	i = 0;
	not_in_quote = CORRECT;
	while (src[i] && i < index)
	{
		if ((src[i] == '\'' || src[i] == '"') && not_in_quote)
			not_in_quote = INCORRECT;
		else if ((src[i] == '\'' || src[i] == '"') && !not_in_quote)
			not_in_quote = CORRECT;
		i++;
	}
	return (not_in_quote);
}

int	ft_at_index(char *src, char c)
{
	int	i;

	i = FIRST_INDEX;
	if (src)
	{
			while (src[i])
			{
				if (src[i] == c)
					if (ft_is_not_in_quotes(src, i))
						return (i);
				i++;
			}
	}
	return (INVALID);
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

int	main()
{
	while (1)
	{
		char* cmd = readline("cmd: ");
		int valid = ft_quote_error(cmd);
		int	in_quotes = ft_is_not_in_quotes(cmd, '|');
		int	index = ft_at_index(cmd, '|');
		if (valid)
			printf("This cmd is valid\n");
		else
			printf("Token error near quote\n");
		if (!in_quotes)
			printf("In quotes\n");
		else
			printf("NOT in quotes\n");
		printf ("Pipe index is: %d\n", index);
	}
}
