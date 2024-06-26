#include "ms.h"
#include <errno.h>

static short	look_for_space(char *s)
{
	size_t	i;

	i = 0;

	if (!s || s[0] == '#')
		return (1);
	while (s && s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == 0 || s[i] == '\n')
		return (1);
	return (0);
}

static char	*read_file(int fd)
{
	char	*tmp;
	char	*join;
	size_t	i;

	tmp = "read";
	join = NULL;
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (look_for_space(tmp) == 0)
		{
			i = ft_strlen(tmp);
			if (i > 1 && tmp[i - 1] == '\n')
				tmp[i - 1] = ';';
			join = ft_strfjoin(join, tmp);
		}
		ft_free(tmp);
	}
	close (fd);
	i = ft_strlen(join);
	if (join && join[i - 1] == ';')
		join[i -1] = '\0';
	return (join);
}

static int	look_name(char *name)
{
	char	*r;

	r = ft_strrchr(name, '.');
	if (r && ft_strncmp(r, ".msrc", 6) == 0)
		return (SUCCESS);
	if (!r || ft_strncmp(r, ".ms", 4) != 0)
	{
		ft_printf(2, "%o"MS_NAME"\b: ms: %s don't end in .ms\n", NULL, name);
		return (FAIL);
	}
	return (SUCCESS);
}

static char	*make_new_str(char *f_name)
{
	int	fd;

	if (look_name(f_name) != SUCCESS)
		return (NULL);
	fd = open(f_name, O_DIRECTORY);
	if (fd > 0)
	{
		ft_printf(2, "%o"MS_NAME"\b: ms: %s is a directory\n", NULL, f_name);
		close(fd);
		return (NULL);
	}
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "%o"MS_NAME"\b: ms: %s %s\n", NULL, f_name, strerror(errno));
		return (NULL);
	}
	return (read_file(fd));
}

int	ms_run(char **av, size_t *j)
{
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (shell)
	{
		*j += 1;
		if (av[0])
		{
			shell->s_in = ft_free(shell->s_in);
			shell->s_in = make_new_str(av[0]);
			if (!shell->s_in)
				return (1);
			return (0);
		}
		else
			ft_printf(2, "%o"MS_NAME"\b: ms: -r "RUN, NULL);
		return (1);
	}
	return (0);
}

int	ms_logic(char **av, size_t *j)
{
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (shell)
	{
		*j += ft_strlen_double(av);
		if (av[0] && av[1])
		{
			shell->s_in = ft_free(shell->s_in);
			if (!shell->pec)
				shell->s_in = ft_strdup(av[0]);
			else
				shell->s_in = ft_strdup(av[1]);
			return (0);
		}
		else
			ft_printf(2, "%o"MS_NAME"\b: ms: "LOGIC, NULL);
		return (1);
	}
	return (0);
}
