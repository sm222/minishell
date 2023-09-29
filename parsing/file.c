#include "parsing.h"

char	*ft_file_extract(char *src, int start_index)
{
	t_idx	i;
	char	*res;

	ft_bzero(&i, sizeof(t_idx));
	i.start_index = start_index + 1;
	if (src[i.start_index] == '>')
		i.start_index++;
	if (src[i.start_index] == ' ')
		i.start_index++;
	i.end_index = i.start_index;
	while (src[i.end_index] && src[i.end_index] != ' ')
		i.end_index++;
	res = ft_strslice(src, i.start_index, i.end_index);
	while (start_index != i.end_index)
		src[start_index++] = PASSED_THROUGH;
	return (res);
}

static int	ft_file_in(char *path, t_token *tokens)
{
	if (tokens->redi_in > 3)
		close(tokens->redi_in);
	if (access(path, F_OK) == 0)
		tokens->redi_in = open(path, O_RDONLY);
	else
	{
		printf("no such file %s\n", path);
		return (INCORRECT);
	}
	return (CORRECT);
}

static int	ft_file_out(char *path, t_token *tokens, char duplicity)
{
	if (tokens->redi_out > 3)
		close(tokens->redi_out);
	if (duplicity == SINGLE_REDIRECT)
		tokens->redi_out = open(path, O_CREAT | O_TRUNC, 0644);
	else if (duplicity == DOUBLE_REDIRECT)
		tokens->redi_out = open(path, O_CREAT | O_APPEND, 0644);
	return (CORRECT);
}

// WIP
int	ft_file_op(char *path, t_token *tokens, char redirect, char duplicity)
{
	if (redirect == '<')
	{
		if (!ft_file_in(path, tokens))
			return (INCORRECT);
	}
	if (redirect == '>')
	{
		if (!ft_file_out(path, tokens, duplicity))
			return (INCORRECT);
	}
	return (CORRECT);
}
