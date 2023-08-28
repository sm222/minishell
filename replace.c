#include <stdio.h>
#include "libft/libft.h"

# define CORRECT 1
# define INVALID -1 
# define INCORRECT 0

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

int ft_input(char *src, int start_index)
{
	int	end_index;
	int	current_start;

	current_start = start_index;
	if (src[start_index + 1] == '<')
		printf("here_doc\n");
	else
		printf("regular input\n");
	start_index++;
	if (src[start_index + 1] == ' ')
		start_index++;
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
		printf("append\n");
	else
		printf("trunk\n");
	start_index++;
	if (src[start_index + 1] == ' ')
		start_index++;
	start_index++;
	end_index = start_index;
	while (src[end_index] > 32 && src[end_index])
	{
		end_index++;
		printf("%d\n", end_index);
	}
	printf("%s\n", ft_strslice(src, start_index, end_index));
	while (current_start != end_index)
		src[current_start++] = 92;
	printf("%s\n", src);
	return 0;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int input;
		int output;
		char *cmd;

		cmd	= av[1];
		printf("length: %d\n", (int)ft_strlen(cmd));
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
	}
	else
		printf("try again\n");
}
