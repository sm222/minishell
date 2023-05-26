#include "minishell.h"

int	main(void)
{
	char	*s;

	s = PROMPT;
	while (s)
	{
		s = readline(PROMPT);
		if (s && *s)
			add_history(s);
		ft_printf("%s\n", s);
		Ct_mprintf(s, ft_strlen(s) + 1, 1, 'A');
		ft_safe_free(s);
	}
	rl_clear_history();
	return (0);
}
