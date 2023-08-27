# include "here_doc.h"

static int	close_and_exit(int fd)
{
	close(fd);
	free_here_dock(0);
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
	int			f;
	mode_t		mode;

	f = stat(doc->f_name, &last);
	mode = last.st_mode;
	while (f == 0)
	{
		f = stat(doc->f_name, &start);
		if (f != 0 || mode != start.st_mode)
		{
			ft_printf(2, "%ominishell: here_doc: file was temperd\n", NULL);
			break ;
		}
		if (write_fd(doc->fd, stop) != 0 || f == -1)
			break ;
		f = stat(doc->f_name, &last);
	}
	if (f == -1)
		perror("minishell: here_doc");
	return (close_and_exit(doc->fd));
}

short	edit_here_doc(t_doc *doc, char *stop)
{
	pid_t	pid;

	if (doc)
	{
		doc->fd = open(doc->f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (doc->fd < 0)
		{
			unlink(doc->f_name);
			return (edit_here_doc(doc, stop));
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
