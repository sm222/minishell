#include <stdio.h>
#include "libft/libft.h"

# define CORRECT 1
# define INVALID -1 
# define INCORRECT 0
# define FIRST_INDEX 0

char	*ft_strslice(char *src, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	if (src)
	{
		res = ft_calloc(end - start, sizeof(char));
		if (!res)
			return (NULL);
		while (start < end)
			res[i++] = src[start++];
		return (res);
	}
	return (NULL);
}

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

	i = 0;
	if (src)
	{
		while (src[i])
			if (src[i++] == c)
				return (i - 1);
	}
	return (INVALID);
}

void	ft_check_here_doc(char *src)
{
	int	i;

	i = FIRST_INDEX;
	while (src[i])
	{
		if (src[i] == '<' && src[i + 1] == '<')
			;
		i++;
	}

}

int ft_input(char *src, int start_index)
{
	int	end_index;
	int	current_start;

	current_start = start_index;
	if (src[start_index + 1] == '<')
	{
		start_index++;
		printf("here_doc\n");
	}
	else
		printf("regular input\n");
	start_index++;
	if (src[start_index] == ' ')
		start_index++;
	end_index = start_index;
	while (src[end_index] > 32 && src[end_index])
		end_index++;
	printf("%s\n", ft_strslice(src, start_index, end_index));
	while (current_start != end_index)
		src[current_start++] = 92;
	printf("%s\n", src);
	return 0;
}

int ft_output(char *src, int start_index)
{	
	int	end_index;
	int	current_start;

	current_start = start_index;
	if (src[start_index + 1] == '>')
	{
		start_index++;
		printf("append\n");
	}
	else
		printf("trunk\n");
	start_index++;
	if (src[start_index] == ' ')
		start_index++;
	end_index = start_index;
	while (src[end_index] > 32 && src[end_index])
		end_index++;
	printf("%s\n", ft_strslice(src, start_index, end_index));
	while (current_start != end_index)
		src[current_start++] = 92;
	printf("%s\n", src);
	return 0;
}

int	ft_redirect_op(char *cmd)
{
	int input;
	int output;

	while (ft_has_redirect(cmd))
	{
		input = ft_at_index(cmd, '<');
		output = ft_at_index(cmd, '>');
		printf("in_index: %d\n", input);
		printf("out_index: %d\n", output);
		if (input != INVALID)
			ft_input(cmd, input);
		if (output != INVALID)
			ft_output(cmd, output);
	}
	return 0;
}

int	ft_invalid_pipe(char *cmd)
{
	int	i;

	i = FIRST_INDEX;
	while (cmd[i])
	{
		if (cmd[i] == '|' && cmd[i + 1] == '|')
		{
			//ft_check_here_doc(cmd);
			printf("do here_doc here\n");
			printf("token error near '|'\n");
			return (CORRECT);
		}
		i++;
	}
	return (INCORRECT);
}

void	ft_pipe_op(char *cmd)
{
	int		pipe_index;
	int		start_index;
	char	*sliced_cmd;

	start_index = FIRST_INDEX;
	if (ft_invalid_pipe(cmd))
		return ;
	while(ft_has_pipe(cmd))
	{
		pipe_index = ft_at_index(cmd, '|');
		sliced_cmd = ft_strslice(cmd, start_index, pipe_index);
		ft_redirect_op(sliced_cmd);
		printf("%s\n", sliced_cmd);
		cmd[pipe_index] = '/';
		start_index = pipe_index;
		free(sliced_cmd);
	}
	pipe_index = (int)ft_strlen(cmd);
	sliced_cmd = ft_strslice(cmd, start_index, pipe_index);
	ft_redirect_op(sliced_cmd);
	printf("%s\n", sliced_cmd);
	free(sliced_cmd);
}

ft_cmd_deconstruct()
{
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *cmd;

		cmd	= ft_strdup(av[1]);
		printf("length: %d\n", (int)ft_strlen(cmd));
		ft_pipe_op(cmd);
		free(cmd);
	}
	else
		printf("try again\n");
}
