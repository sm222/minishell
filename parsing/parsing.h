# include "../execution/execution.h"

# define CORRECT 1
# define INCORRECT 0

typedef struct	s_parse
{
	char *content;
	s_ next;
	s_ prev;
}	t_parse;

int	ft_parsing(char *src);
int	ft_has_pipe(char *src);
int	ft_at_index(char *src, char c);
