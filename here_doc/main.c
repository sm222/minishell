# include "here_doc.h"

int main(void)
{
	t_doc	*doc;

	doc = NULL;
	ft_return_ptr(&doc, DOC);
	int	i = 0;
	while (i < 10)
	{
		make_here_doc(i, "eof");
		printf("%dend\n", i++);
	}
	free_here_doc(1);
}