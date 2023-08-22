# include "here_doc.h"

int main(void)
{
	t_doc	*doc;

	doc = NULL;
	ft_return_ptr(&doc, DOC);
	make_here_doc(0, "here");
	printf("end1\n");
	make_here_doc(0, "here2");
	printf("end2\n");
	make_here_doc(0, "he");
	printf("end3\n");
	free_here_dock();
}