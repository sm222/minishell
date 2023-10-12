#include "here_doc.h"

/// @brief make a new here_doc node
/// @param f err flag
/// @return new one or NULL if fail
t_doc	*new_doc(int *f)
{
	t_doc	*new;
	static	unsigned int i;

	new = ft_calloc(1, sizeof(t_doc));
	*f = M_FAIL;
	if (!new)
		return (NULL);
	if (ft_printf(NO_PRINT, "%o/tmp/.here_doc%u", &new->f_name, i++) == -1)
		return (ft_free(new));
	*f = SUCCESS;
	return (new);
}

/// @brief use to add a here_doc node at the end
/// @param list *list of here_doc
/// @param f flag to return err code
/// @param i index of new here_doc, or modefi it if all ready exist
/// @param stop word to stop on
/// @return 
static int	make_here_doc_last(t_doc **list, short inter, char *stop)
{
	t_doc	*tmp;
	int		err;

	err = 0;
	tmp = (*list);
	if (!tmp)
	{
		*list = new_doc(&err);
		if (err != SUCCESS)
			return (-1);
		return (edit_here_doc(*list, stop, inter));
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_doc(&err);
	if (err != SUCCESS)
		return (-1);
	return (edit_here_doc(tmp->next, stop, inter));
}

/// @brief use to add a here_doc
/// @param inter interpret the $
/// @param stop word to stop on
/// @return err code or fd of file
int	make_here_doc(char inter, char *stop)
{
	t_doc	**doc_list;
	int		err;

	err = 0;
	if (!stop)
		return (BAD_ARGS + 1);
	doc_list = ft_return_ptr(NULL, DOC);
	err = make_here_doc_last(doc_list, inter, stop);
	return (err);
}
