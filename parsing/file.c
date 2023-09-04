#include "parsing.h"

// WIP
void	ft_file_op(char *path, t_token *tokens, char redirect, char duplicity)
{
	if (redirect == '<')
	{
		if (tokens->redi_in > 3)
			close(tokens->redi_in);
		if (duplicity == DOUBLE_REDIRECT)
			;
			//get_here_doc(path); // temp function TO BE REPLACED
		else
		{
			if (access(path, F_OK) == 0)
				tokens->redi_in = open(path, O_RDONLY);
			else
				printf("no such file %s\n", path);
		}
	}
	if (redirect == '>')
	{
		if (tokens->redi_out > 3)
			close(tokens->redi_out);
		if (duplicity == SINGLE_REDIRECT)
			tokens->redi_out = open(path, O_CREAT | O_TRUNC);
		else if (duplicity == DOUBLE_REDIRECT)
			tokens->redi_out = open(path, O_CREAT | O_APPEND);
	}
}
