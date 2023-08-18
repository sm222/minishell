# include "here_doc.h"

t_doc	*new_doc(void)
{
	static int	i = 0;
	t_doc	*new;

	new = ft_calloc(1, sizeof(t_doc));
	if (!new)
		return (NULL);
	if (ft_printf(NO_PRINT, "%o/tmp/.here_doc%d", &new->f_name, i) == -1)
		return (ft_free(new));
	new->fd = open(new->f_name, O_CREAT | O_TRUNC, 0644);
	if (new->fd < 0)
	{
		ft_printf(STDERR_FILENO, "%ominishell: can't make %s", \
		NULL ,new->f_name);
		ft_free(new->f_name);
		return (ft_free(new));
	}
	new->i = i++;
	close(new->fd);
	return (new);
}


static short	edit_loop(t_doc *doc)
{
	struct stat	last;
	char		*tmp;

	(void)last;
	if (fstat(doc->fd, &doc->data) == -1)
		return (NO_ASS);
	tmp = "t";
	while (tmp)
	{
		tmp = readline("here_doc");
		if (tmp)
			free(tmp);
	}
	return (SUCCESS);
}


short	edit_here_doc(t_doc *doc)
{
	if (doc)
	{
		doc->fd = open(doc->f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (!doc->fd)
		{
			perror("edit_here_doc");
			return (FAIL);
		}
		edit_loop(doc);
	}
	return (BAD_ARGS);
}
