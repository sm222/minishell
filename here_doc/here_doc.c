#include "here_doc.h"

short	make_here_doc(int i)
{
	t_doc	**doc;

	(void)i;
	doc = ft_return_ptr(NULL, DOC); 
	if (!*doc)
	{
		*doc = new_doc();
	}
	
	return (SUCCESS);
}

int	get_here_doc(int i)
{
	(void)i;
	return (SUCCESS);
}
int	free_here_dock(void)
{
	return (SUCCESS);
}

/**
 * @brief 
 *  test
 * ! test
 * ? test
 * TODO: test
**/