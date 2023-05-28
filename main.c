#include "minishell.h"
 
int	main(void)
{
	char	*s;
	int		fd;

	s = PROMPT;
	fd = open("test", O_CREAT | O_TRUNC | O_RDWR, 0644);
	while (s)
	{
		s = readline(PROMPT);
		if (s && *s)
			add_history(s);
		ft_free(s);
	}
	close(fd);
	rl_clear_history();
	return (0);
}
