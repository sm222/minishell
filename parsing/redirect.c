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
		{
			if (!ft_strchr("<>|", src[i + 2]))
				printf("here_doc\n");
		}
		i++;
	}
}

int	ft_input(char *src, t_token *tokens, int start_index)
{
	int		res;
	char	*file;
	char	duplicity;

	(void)tokens;
	res = CORRECT;
	duplicity = SINGLE_REDIRECT;
	file = ft_file_extract(src, start_index);
	printf("printf: %s\n", file);
	free(file);
	return (res);
}

int	ft_output(char *src, t_token *tokens, int start_index)
{
	int		res;
	char	*file;
	char	duplicity;

	(void)tokens;
	res = CORRECT;
	if (src[start_index + 1] == '>')
		duplicity = DOUBLE_REDIRECT;
	else
		duplicity = SINGLE_REDIRECT;
	file = ft_file_extract(src, start_index);
	printf("printf: file: %s\n", file);
	res = ft_file_op(file, tokens, '>', duplicity);
	free(file);
	return (res);
}

int	ft_redirect_op(char *cmd, t_token *tokens)
{
	int	input;
	int	fd_in;
	int	output;
	int	fd_out;

	fd_in = 0;
	fd_out = 0;
	(void)tokens;
	ft_check_here_doc(cmd);
	while (ft_has_redirect(cmd))
	{
		input = ft_at_index(cmd, '<');
		output = ft_at_index(cmd, '>');
		if (input == ERROR)
			return (ERROR);
		if (input != INVALID)
			fd_in = ft_input(cmd, tokens, input);
		if (output != INVALID)
			fd_out = ft_output(cmd, tokens, output);
	}
	return (CORRECT);
}
