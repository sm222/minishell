# include "here_doc.h"

int main(void)
{
	t_doc	*doc;

	doc = NULL;
	ft_return_ptr(&doc, DOC);
	int fd = make_here_doc(1, ft_strdup("eof"));
	printf("fd = %d\n", fd);
	free_here_doc(1);
}