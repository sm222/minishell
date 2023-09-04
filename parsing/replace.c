#include "parsing.h"

void	ft_purge(char **decon, char *cmd);
char	**ft_cmd_deconstruct(char *cmd);
void	*ft_clear_array(char **src);

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

int	ft_at_index(char *src, char c)
{
	int	i;

	i = FIRST_INDEX;
	if (src)
	{
		while (src[i])
			if (src[i++] == c)
				return (i - 1);
	}
	return (INVALID);
}

void	ft_purge(char **decon, char *src)
{
	ft_clear_array(decon);
	ft_xfree(src);
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
	while(ft_has_pipe(cmd))
	{
		pipe_index = ft_at_index(cmd, '|');
		sliced_cmd = ft_strslice(cmd, start_index, pipe_index);
		decon = ft_cmd_deconstruct(sliced_cmd);
		cmd[pipe_index] = 92; // TO BE CHANGED, REPLACE WITH PASSED_THROUGH
		start_index = pipe_index;
		ft_pass_through(decon);
		ft_purge(decon, sliced_cmd);
	}
	pipe_index = (int)ft_strlen(cmd);
	sliced_cmd = ft_strslice(cmd, start_index, pipe_index);
	decon = ft_cmd_deconstruct(sliced_cmd);
	ft_pass_through(decon);
	ft_purge(decon, sliced_cmd);
}

char **ft_cmd_deconstruct(char *cmd, t_loc *list) 
{
	int		start_index;
	int		end_index;
	char	*current;
	char	**res;
	int		i;

	i = FIRST_INDEX;
	res = NULL;
	if (!cmd)
		return res;
	ft_redirect_op(cmd);
	while (cmd[i])
	{
		while (cmd[i] == 92 || cmd[i] == ' ') // TO BE CHANGED, REPLACE WITH PASSED_THROUGH
			i++;
		start_index = i;
		while (cmd[i] != 92 && cmd[i] > 32) // TO BE CHANGED, REPLACE WITH PASSED_THROUGH
			i++;
		end_index = i;
		current = ft_strslice(cmd, start_index, end_index);
		res = ft_arrayjoin(res, current);
		free(current);
	}
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
