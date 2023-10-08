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
		ft_free(shell->rest);
	}
	close(fd);
	free_here_doc(NO_UNLINK);
	exit(0);
}

/// @brief use readline in a loop to witre in the file
/// @param fd file
/// @param stop word to stop on
/// @param inter look if it need to change dolar singne or not
/// @return return FAIL while it take input, other wise.
/// @return SUCCESS at the end or M_fail if control + d
static int	write_fd(int fd, char *stop, short inter)
{
	char	*tmp;
	int		*pec;

	pec = ft_return_ptr(NULL, PEC);
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
	if (inter)
		ft_change_dolar(&tmp, ft_return_ptr(NULL, ENV_C), 1, *pec);
	ft_putendl_fd(tmp, fd);
	free(tmp);
	return (FAIL);
}

/// @brief use to edit a here_doc
/// @param doc node of here_duc
/// @param stop word to stop on
/// @return err value
static short	edit_loop(t_doc *doc, char *stop, short inter)
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
		if (write_fd(doc->fd, stop, inter) != 0 || f == -1)
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
int	edit_here_doc(t_doc *doc, char *stop, short inter)
{
	pid_t	pid;

	if (doc)
	{
		pid = fork();
		if (pid == -1)
			return (FORK_FAIL + 2);
		if (pid == 0)
		{
			doc->fd = open(doc->f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
			if (doc->fd < 0)
			{
				ft_printf(2, "%o"MS_NAME"\b: can't make file %s\n", \
			NULL, doc->f_name);
				free_here_doc(0);
				ft_free(stop);
				exit(1);
			}
			edit_loop(doc, stop, inter);
		}
		else
			waitpid(pid, NULL, 0);
	}
	doc->fd = open(doc->f_name, O_RDONLY, 0644);
	return (doc->fd);
}
