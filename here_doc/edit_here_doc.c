# include "here_doc.h"

/// @brief use at the end of the edit_here_doc
/// @param fd of the open here_doc
/// @return 
static int	close_and_exit(int fd)
{
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (shell)
	{
		ft_double_sfree((void **)shell->en);
		ft_double_sfree((void **)shell->path);
		ft_free(shell->pwd);
		ft_free(shell->s);
		ft_free(shell->prompt);
	}
	close(fd);
	free_here_doc(0);
	exit(0);
}

/// @brief use readline in a loop to witre in the file
/// @param fd file
/// @param stop word to stop on
/// @return return FAIL while it take input, other wise.
/// @return SUCCESS at the end or M_fail if control + d
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

/// @brief use to edit a here_doc
/// @param doc node of here_duc
/// @param stop word to stop on
/// @return err value
static short	edit_loop(t_doc *doc, char *stop)
{
	int			f;
	mode_t		mode;

	f = stat(doc->f_name, &doc->last);
	mode = doc->last.st_mode;
	while (f == 0)
	{
		f = stat(doc->f_name, &doc->start);
		if (f != 0 || mode != doc->start.st_mode)
		{
			ft_printf(2, "%ominishell: here_doc: file was temperd\n", NULL);
			break ;
		}
		if (write_fd(doc->fd, stop) != 0 || f == -1)
			break ;
		f = stat(doc->f_name, &doc->last);
	}
	if (f == -1)
		perror("minishell: here_doc");
	return (close_and_exit(doc->fd));
}

/// @brief modefi a here_doc
/// @param doc to edit
/// @param stop word to stop on
/// @return err code
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
			close(doc->fd);
		}
		return (SUCCESS);
	}
	return (BAD_ARGS);
}
