#include "include/minishell.h"

static void	bad_con(char *s, short *type)
{
	int		*pec;
	size_t	i;

	i = 0;
	pec = ft_return_ptr(NULL, PEC);
	while (s[i])
	{
		if (s[i] == '&' || s[i] == '|')
		{
			if ((s[i + 1] == '\0') || (s[i] == '&' && s[i + 1] != '&') || \
				(s[i] == '|' && s[i + 1] == '&') || \
				(s[i + 2] && s[i + 2] == s[i]) || find_end(s, i))
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
	while (s && s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (!s[i] || s[i] == '|' || s[i] == '&')
		return (1);
	return (0);
}

size_t	look_for_type(char *s, short *type)
{
	size_t	i;

	i = 0;
	*type = 0;
	ft_set_mode(-1);
	bad_con(s, type);
	if (*type == -1)
		return (FAIL);
	while (s[i])
	{
		ft_set_mode(s[i]);
		while (s[i] && ft_set_mode(0) > 0)
			ft_set_mode(s[i++]);
		if ((s[i] == '&' && s[i + 1] == '&' && s[i + 2]) || \
			(s[i] == '|' && s[i + 1] == '|' && s[i + 2]))
			break ;
		i++;
	}
	*type = s[i];
	return (i);
}
