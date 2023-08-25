# include "here_doc.h"

static int	close_and_exit(int fd)
{
	close(fd);
	exit(0);
}

static int	write_fd(int fd, char *stop)
{
	char	*tmp;

	tmp = readline("> ");
	if (ft_strncmp(stop, tmp, ft_strlen(stop) + 1) == 0)
	{
		free(tmp);
		return (SUCCESS);
	}
	if (!tmp)
	{
		rl_redisplay();
		return (M_FAIL);
	}
	ft_putendl_fd(tmp, fd);
	free(tmp);
	return (FAIL);
}


static short	edit_loop(t_doc *doc, char *stop)
{
	struct stat	start;
	struct stat	last;

	while (1)
	{
		if (write_fd(doc->fd, stop) != 0)
			break ;
	}
	return (close_and_exit(doc->fd));
}

short	edit_here_doc(t_doc *doc, char *stop)
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
			edit_loop(doc, stop);
		else
		{
			waitpid(pid, NULL, 0);
			close (doc->fd);
		}
		return (SUCCESS);
	}
	return (BAD_ARGS);
}
