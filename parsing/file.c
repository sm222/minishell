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
	if (tokens->redi_in > 2)
		close(tokens->redi_in);
	if (access(path, F_OK) == 0)
		tokens->redi_in = open(path, O_RDONLY);
	else
	{
		ft_printf(2, MS_NAME"\b: %s: no such file or directory\n", path);
		return (INCORRECT);
	}
	return (CORRECT);
}

static int	ft_file_out(char *path, t_token *tokens, char duplicity)
{
	if (tokens->redi_out > 2)
		close(tokens->redi_out);
	if (duplicity == SINGLE_REDIRECT)
		tokens->redi_out = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (duplicity == DOUBLE_REDIRECT)
		tokens->redi_out = open(path, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (tokens->redi_out == INVALID)
	{
		ft_printf(2, MS_NAME"\b: %s: can't access file\n", path);
		return (INCORRECT);
	}
	return (CORRECT);
}

int	ft_file_op(char *path, t_token *tokens, char redirect, char duplicity)
{
	if (redirect == '<')
	{
		if (!ft_file_in(path, tokens))
			return (INVALID);
	}
	if (redirect == '>')
	{
		if (!ft_file_out(path, tokens, duplicity))
			return (INVALID);
	}
	return (CORRECT);
}
