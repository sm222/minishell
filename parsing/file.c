#include "parsing.h"

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
		tokens->redi_out = open(path, O_CREAT | O_TRUNC);
	else if (duplicity == DOUBLE_REDIRECT)
		tokens->redi_out = open(path, O_CREAT | O_APPEND);
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
