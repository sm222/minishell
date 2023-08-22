#include "here_doc.h"

int	free_here_dock(void)
{
	t_doc	**doc;
	t_doc	*tmp;
	t_doc	*next;

	doc =  ft_return_ptr(NULL, DOC);
	if (!doc)
		return (BAD_ARGS);
	if (!*doc)
		return (SUCCESS);
	tmp = *doc;
	while (tmp)
	{
		if (tmp->f_name)
		{
			if (unlink(tmp->f_name))
				perror("unlink");
			ft_free(tmp->f_name);
		}
		next = tmp->next;
		ft_free(tmp);
		tmp = next;
	}
	return (SUCCESS);
}
