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

int	ft_input(char *src, t_token *tokens, int start_index)
{
	int		res;
	char	*file;
	char	duplicity;

	res = CORRECT;
	duplicity = SINGLE_REDIRECT;
	file = ft_file_extract(src, start_index);
	res = ft_file_op(file, tokens, '<', duplicity);
	free(file);
	return (res);
}

int	ft_output(char *src, t_token *tokens, int start_index)
{
	int		res;
	char	*file;
	char	duplicity;

	res = CORRECT;
	if (src[start_index + 1] == '>')
		duplicity = DOUBLE_REDIRECT;
	else
		duplicity = SINGLE_REDIRECT;
	file = ft_file_extract(src, start_index);
	res = ft_file_op(file, tokens, '>', duplicity);
	free(file);
	return (res);
}

int	ft_redirect_op(char *cmd, t_token *tokens)
{
	t_rdct	fd;

	ft_bzero(&fd, sizeof(t_rdct));
	fd.fd_doc = ft_here_doc(cmd, &fd);
	tokens->redi_doc = fd.fd_doc;
	while (ft_has_redirect(cmd))
	{
		fd.input = ft_at_index(cmd, '<');
		fd.output = ft_at_index(cmd, '>');
		if (fd.input == ERROR)
			return (ERROR);
		if (fd.input != INVALID)
			fd.in_succ = ft_input(cmd, tokens, fd.input);
		if (fd.output != INVALID)
			fd.out_succ = ft_output(cmd, tokens, fd.output);
	}
	if (fd.in_succ == INVALID || fd.out_succ == INVALID || \
		fd.fd_doc == INVALID)
		return (INCORRECT);
	if (fd.last_doc)
		tokens->redi_in = fd.fd_doc;
	return (CORRECT);
}
