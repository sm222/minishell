# include "here_doc.h"

int main(void)
{
	t_doc	*doc;

	doc = NULL;
	ft_return_ptr(&doc, DOC);
	if (make_here_doc(0) < SUCCESS)
		printf("bad\n");
	if (make_here_doc(0) < SUCCESS)
		printf("bad\n");
}