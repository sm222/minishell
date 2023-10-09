#include "here_doc.h"


/// @brief DON'T USE
/// @param i 
/// @return 
int	get_here_doc(int i)
{
	int		fd;
	t_doc	**doc;
	t_doc	*tmp;

	doc = ft_return_ptr(NULL, DOC);
	if (!*doc || i < 0)
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
		fd = open(tmp->f_name, O_RDONLY);
		return (fd);
	}
	return (-1);
}

/**
 * @brief 
 * * test
 * ! test
 * ? test
 * TODO: test
**/