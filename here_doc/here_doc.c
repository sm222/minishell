#include "here_doc.h"

short	make_here_doc(int i)
{
	t_doc	**doc;
	t_doc	*tmp;

	doc = ft_return_ptr(NULL, DOC);
	if (!*doc)
	{
		*doc = new_doc();
		if (!*doc)
			return (FAIL);
	}
	tmp = (*doc);
	while (tmp->i != i)
		tmp = tmp->next;
	if (!tmp)
		return (FAIL);
	else
		edit_here_doc(tmp);
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
 * * test
 * ! test
 * ? test
 * TODO: test
**/