# include "here_doc.h"

int main(void)
{
	t_doc	*doc;

	doc = NULL;
	ft_return_ptr(&doc, DOC);
	make_here_doc(0);
	printf("tell me why\n");
	make_here_doc(0);
	free_here_dock();
}