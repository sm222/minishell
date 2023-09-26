#include "parsing.h"

int	ft_has_redirect(char *src)
{
	int	i;

	i = -1;
	if (src)
	{
		while (src[++i])
			if (src[i] == '<' || src[i] == '>')
				if (ft_is_not_in_quotes(src, i))
					return (CORRECT);
	}
	return (INCORRECT);
}

void	ft_check_here_doc(char *src)
{
	int	i;

	i = FIRST_INDEX;
	while (src && src[i])
	{
		if (src[i] == '<' && src[i + 1] == '<')
			printf("here_doc\n");
		i++;
	}
}

int	ft_input(char *src, int start_index)
{
	int		end_index;
	int		current_start;
	char	*file;

	current_start = start_index;
	printf("printf: regular input\n");
	start_index++;
	if (src[start_index] == ' ')
		start_index++;
	end_index = start_index;
	while (src[end_index] > CHAR_LIMIT && src[end_index])
		end_index++;
	file = ft_strslice(src, start_index, end_index);
	printf("printf: %s\n", file);
	free(file);
	while (current_start != end_index)
		src[current_start++] = PASSED_THROUGH;
	return (0);
}

int	ft_output(char *src, int start_index)
{
	int		end_index;
	int		current_start;
	char	*file;

	current_start = start_index;
	if (src[start_index + 1] == '>')
	{
		start_index++;
		printf("printf: append\n");
	}
	else
		printf("printf: trunk\n");
	start_index++;
	if (src[start_index] == ' ')
		start_index++;
	end_index = start_index;
	while (src[end_index] > CHAR_LIMIT && src[end_index])
		end_index++;
	file = ft_strslice(src, start_index, end_index);
	printf("printf: %s\n", file);
	free(file);
	while (current_start != end_index)
		src[current_start++] = PASSED_THROUGH;
	return (0);
}

t_token	*ft_redirect_op(char *cmd)
{
	int		input;
	int		fd_in;
	int		output;
	int		fd_out;
	t_token	*tokens;

	tokens = NULL;
	fd_in = -1;
	fd_out = 0;
	ft_check_here_doc(cmd);
	while (ft_has_redirect(cmd))
	{
		input = ft_at_index(cmd, '<');
		output = ft_at_index(cmd, '>');
		if (input == ERROR)
			return (NULL);
		if (input != INVALID)
			fd_in = ft_input(cmd, input);
		if (output != INVALID)
			fd_out = ft_output(cmd, output);
	}
	return (tokens);
}
