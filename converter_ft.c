#include "include/minishell.h"
#include "parsing/parsing.h"

static int	find_tok(char *s)
{
	size_t	i;
	short	find;

	i = 0;
	find = 0;
	while (s && s[i])
	{
		ft_set_mode(s[i]);
		if (s[i] == '|' && ft_set_mode(0) == 0)
		{
			return (0);
		}
		if (ft_isprint(s[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static short	look_at_pipe(char *s, size_t i)
{
	if (find_tok(s) == 0)
		return (1);
	if (s[i] && s[i + 1])
	{
		if (s[i] == '|' && s[i + 1] == '|')
		{
			if (find_tok(s + i + 2) == 0)
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

static void	bad_con(char *s, short *type)
{
	int		*pec;
	size_t	i;

	i = 0;
	pec = ft_return_ptr(NULL, PEC);
	while (s && i < ft_strlen(s))
	{
		while (s && s[i] && ft_set_mode(s[i]) != 0)
			ft_set_mode(s[++i]);
		if ((s[i] == '&' || s[i] == '|') && ft_set_mode(s[i]) == 0)
		{
			if ((s[i + 1] == '\0') || (s[i] == '&' && s[i + 1] != '&') || \
				(s[i] == '|' && s[i + 1] == '&') || find_end(s, i) || \
				find_tok(s) == 0 || look_at_pipe(s, i))
			{
				ft_printf(2, "%o"MS_NAME"\b: "SENUT" `%c\'\n", NULL, s[i]);
				*pec = 258;
				*type = -1;
				break ;
			}
			i++;
		}
		i++;
	}
}

short	find_end(char *s, size_t start)
{
	size_t	i;


	i = start + 2;
	if (s && (s[i - 1] == '\'' || s[i - 1] == '"'))
		return (0);
	while (s && s[i] && (s[i] == ' ' || s[i] == '\t'))
		ft_set_mode(s[++i]);
	if (!s[i] || ((s[i] == '|' || s[i] == '&') && ft_set_mode(s[i]) == 0))
		return (1);
	return (0);
}

size_t	look_for_type(char *s, short *type)
{
	size_t	i;

	i = 0;
	*type = 0;
	bad_con(s, type);
	if (*type == -1)
		return (FAIL);
	ft_set_mode(-1);
	while (s && i < ft_strlen(s) && ft_set_mode(s[i]) != 1000)
	{
		while (s[i] && ft_set_mode(0) != 0)
			ft_set_mode(s[++i]);
		if (s[i] && s[i + 1])
		{
			if ((s[i] == '&' && s[i + 1] == '&' && s[i + 2]) || \
				(s[i] == '|' && s[i + 1] == '|' && s[i + 2]))
				break ;
		}
		i++;
	}
	if (i < ft_strlen(s))
		*type = s[i];
	return (i);
}

//ls || '|'
//ls 'ads ||'

//ls||'|'