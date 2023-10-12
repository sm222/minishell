#include "execution.h"

int	free_and_dup_in_run(t_cmd *in)
{
	int	(*free_doc)(short);

	free_doc = NULL;
	free_doc = ft_return_ptr(NULL, FREE_DOC);
	dup_in_out(in);
	close_all_fd(in);
	if (in->tok->redi_in == -1)
		close(STDIN_FILENO);
	in->tok = ft_free(in->tok);
	if (free_doc)
		free_doc(NO_UNLINK);
	return (1);
}