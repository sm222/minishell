# include "here_doc.h"

/// @brief DEV CODE
/// @param ac 
/// @param av 
/// @param en 
/// @return 
int main(int ac, char **av, char **en)
{
	t_doc	*doc;
	char	**env;
	int		pec;

	pec = 0;
	(void)av;
	(void)ac;
	doc = NULL;
	env = ft_cpy_double_char(en);
	ft_return_ptr(&doc, DOC);
	ft_return_ptr(env, ENV_C);
	ft_return_ptr(&pec, PEC);
	ft_return_ptr(NULL, SYS);
	char	*name = ft_strdup("eof");
	int fd = make_here_doc(1, name);
	printf("fd = %d\n", fd);
	char	*s = "t";
	while (s)
	{
		s = get_next_line(fd);
		printf("F:%s", s);
		ft_free(s);
	}
	close(fd);
	free(name);
	free_here_doc(1);
	ft_double_sfree((void **) env);
}

//	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=/tmp/supp.txt ./minishell