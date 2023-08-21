# include "here_doc.h"

t_doc	*new_doc(int *f, int *i)
{
	t_doc	*new;

	new = ft_calloc(1, sizeof(t_doc));
	*f = M_FAIL;
	if (!new)
		return (NULL);
	if (ft_printf(NO_PRINT, "%o/tmp/.here_doc%d", &new->f_name, *i) == -1)
		return (ft_free(new));
	*f = SUCCESS;
	new->fd = open(new->f_name, O_CREAT | O_TRUNC, 0644);
	if (new->fd < 0)
	{
		*f = OPEN_FAIL;
		ft_printf(STDERR_FILENO, "%ominishell: can't make %s", \
		NULL ,new->f_name);
		ft_free(new->f_name);
		return (ft_free(new));
	}
	new->i = *i += 1;
	close(new->fd);
	return (new);
}


static short	make_here_doc_last(t_doc **list, int *f, int *j, int i)
{
	t_doc	*tmp;
	t_doc	*last;

	(void)j;
	(void)f;
	tmp = (*list);
	while (tmp)
	{
		if (tmp->i == i)
			break ;
		last = tmp;
		tmp = tmp->next;
	}
	if (tmp)
		printf("%d][%d\n", i, tmp->i);
	else
		printf("%d][%d\n", i, last->i);
	return (SUCCESS);
}


short	make_here_doc(int i)
{
	static int	j = 0;
	t_doc		**doc;
	int			err;

	if (i < 0)
		return (BAD_ARGS);
	doc = ft_return_ptr(NULL, DOC);
	if (!*doc)
	{
		*doc = new_doc(&err, &j);
		if (err < SUCCESS)
			return (err);
		return (edit_here_doc(*doc));
	}
	make_here_doc_last(doc, &err, &j, i);
	return (SUCCESS);
}
