#include "parsing.h"

int	ft_has_redirect(char *src)
{
	int	i;

	i = -1;
	if (src)
	{
		while (src[++i])
			if (src[i] == '<' || src[i] == '>')
				return (CORRECT);
	}
	return (INCORRECT);
}

int	ft_has_pipe(char *src)
{
	int	i;

	i = -1;
	if (src)
	{
		while (src[++i])
			if (src[i] == '|')
				return (CORRECT);
	}
	return (INCORRECT);
}

void	ft_purge(char **decon, char *src)
{
	ft_clear_array(decon);
	ft_free(src);
}

void	ft_check_here_doc(char *src)
{
	int	i;

	i = FIRST_INDEX;
	while (src[i])
	{
		if (src[i] == '<' && src[i + 1] == '<')
			printf("here_doc\n");
		i++;
	}

}

int	ft_invalid_pipe(char *cmd)
{
	int	i;

	i = FIRST_INDEX;
	while (cmd[i])
	{
		if (cmd[i] == '|' && cmd[i + 1] == '|')
		{
			ft_check_here_doc(cmd);
			printf("printf: do here_doc here\n");
			ft_putendl_fd("token error near '|'\n", 2);
			return (CORRECT);
		}
		i++;
	}
	return (INCORRECT);
}

void	ft_pass_through(char **decon)
{
	int	i;
	
	i = FIRST_INDEX;
	while (decon[i])
		ft_putendl_fd(decon[i++], 1);
}

void	ft_pipe_op(char *cmd, t_loc *list)
{
	int		pipe_index;
	int		start_index;
	char	*sliced_cmd;
	char	**decon;

	start_index = FIRST_INDEX;
	if (ft_invalid_pipe(cmd))
		return ;
	while (ft_has_pipe(cmd))
	{
		pipe_index = ft_at_index(cmd, '|');
		sliced_cmd = ft_strslice(cmd, start_index, pipe_index);
		decon = ft_cmd_deconstruct(sliced_cmd, list);
		cmd[pipe_index] = PASSED_THROUGH;
		start_index = pipe_index;
		ft_add_loc(&list, decon);
		ft_free(sliced_cmd);
	}
	pipe_index = (int)ft_strlen(cmd);
	sliced_cmd = ft_strslice(cmd, start_index, pipe_index);
	decon = ft_cmd_deconstruct(sliced_cmd, list);
	ft_add_loc(&list, decon);
	ft_free(sliced_cmd);
}

char **ft_cmd_deconstruct(char *cmd, t_loc *list) 
{
	t_idx	index;
	char	*current;
	//char	*quotes;
	char	**res;
	int		i;

	(void)list;
	i = FIRST_INDEX;
	res = NULL;
	if (!cmd)
		return res;
	ft_redirect_op(cmd);
	while (cmd[i])
	{
		while (cmd[i] == PASSED_THROUGH || cmd[i] == ' ')
			i++;
		index.start_index = i;
		while (cmd[i] != PASSED_THROUGH && cmd[i] > CHAR_LIMIT)
			i++;
		index.end_index = i;
		current = ft_strslice(cmd, index.start_index, index.end_index);
		res = ft_arrayjoin(res, current);
		free(current);
	}
	/*if (quotes)
	{
		res = ft_arrayjoin(res, quotes);
		
	}*/
	return (res);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *cmd;
		t_loc *list;

		cmd	= ft_strdup(av[1]);
		list = NULL;
		ft_pipe_op(cmd, list);
		free(cmd);
	}
	else
		printf("try again\n");
}
