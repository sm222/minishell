# include "here_doc.h"

t_doc	*new_doc(void)
{
	static int	i = 0;
	t_doc	*new;

	new = ft_calloc(1, sizeof(t_doc));
	if (!new)
		return (NULL);
	if (ft_printf(NO_PRINT, "%o/tmp/here_doc%d", &new->f_name, i++) == -1)
		return (ft_free(new));
	new->fd = open(new->f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (new->fd < 0)
	{
		ft_printf(STDERR_FILENO, "%ominishell: can't make %s", \
		NULL ,new->f_name);
		ft_free(new->f_name);
		return (ft_free(new));
	}
	fstat(new->fd, &new->dat);
	return (new);
}
