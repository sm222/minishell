# include "here_doc.h"

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
		tmp = readline("here_doc ");
		if (tmp)
			ft_putendl_fd(tmp, doc->fd);
		ft_free(tmp);
	}
	ft_printf(2, "%oici\n", NULL);
	close(doc->fd);
	exit(0);
	return (SUCCESS);
}

short	edit_here_doc(t_doc *doc)
{
	pid_t	pid;

	if (doc)
	{
		doc->fd = open(doc->f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (!doc->fd)
		{
			perror("edit_here_doc");
			return (FAIL);
		}
		pid = fork();
		if (pid == -1)
			return (FORK_FAIL);
		if (pid == 0)
			edit_loop(doc);
		else
		{
			waitpid(pid, NULL, 0);
			close (doc->fd);
		}
		return (SUCCESS);
	}
	return (BAD_ARGS);
}

