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
	printf("%d\n", get_here_doc(0));
	//free_here_dock();
}