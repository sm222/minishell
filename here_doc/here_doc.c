#include "here_doc.h"

int	get_here_doc(int i)
{
	t_doc	**doc;
	int		err;
	t_doc	*tmp;
	int		fd;


	if (i < 0)
		return (BAD_ARGS);
	doc = ft_return_ptr(NULL, DOC);
	if (!*doc)
		return (-1);
	tmp = (*doc);
	while (tmp)
	{
		if (tmp->i == i)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
	{
		return()
	}
	return ();
}



/**
 * @brief 
 * * test
 * ! test
 * ? test
 * TODO: test
**/