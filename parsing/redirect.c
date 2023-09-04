#include "parsing.h"

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
	return 0;
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
	return 0;
}

int	ft_redirect_op(char *cmd)
{
	int input;
	int output;

	ft_check_here_doc(cmd);
	while (ft_has_redirect(cmd))
	{
		input = ft_at_index(cmd, '<');
		output = ft_at_index(cmd, '>');
		if (input != INVALID)
			ft_input(cmd, input);
		if (output != INVALID)
			ft_output(cmd, output);
	}
	return 0;
}
