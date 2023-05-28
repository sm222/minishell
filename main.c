#include "minishell.h"

int	main(void)
{
	char	*s;
	int		fd;
	t_cmd	*list;

	s = PROMPT;
	fd = open("test", O_CREAT | O_TRUNC | O_RDWR, 0644);

	while (s)
	{
		s = readline(PROMPT);
		if (s && *s)
		{
			add_history(s);
			printf("%d\n", cmd_make_node_last(&list, ft_split(s, ' '), 0));
		}
		ft_free(s);
	}
	cmd_free(list);
	close(fd);
	rl_clear_history();
	return (0);
}
