#include "todo.h"

int	ft_at_index(char *src, char c)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
			if (src[i++] == c)
				return (i - 1);
	}
	return (INVALID);
}

int	ft_at_rev_index(char *src, char c)
{
	int	i;

	if (src)
	{
		i = ft_strlen(src);
		while (src[--i])
			if (src[i] == c)
				return (i - 1);
	}
	return (INVALID);
}

int	ft_list_count(t_flag *head)
{
	int		i;
	t_flag	*current;

	i = 0;
	current = head;
	if (head)
	{
		while (current->next)
		{
			//printf("%s\n", current->flag);
			current = current->next;
			i++;
		}
		i++;
	}
	return (i);
}

void	ft_pipe_op(char *cmd)
{
	int		pipe_index;
	char	*full_cmd;
	char	*current;
	char	*temp;

	current = cmd;
	while (ft_at_index(current, '|') != INVALID)
	{
		temp = current;
		pipe_index = ft_at_index(current, '|');
		full_cmd = ft_strslice(current, FIRST_INDEX, pipe_index);
		current = ft_strslice(current, pipe_index, ft_strlen(cmd));
		ft_cmd_deconstruct(full_cmd);
		free(full_cmd);
		free(temp);
	}
	ft_cmd_deconstruct(current);
	if (ft_at_index(cmd, '|') != INVALID)
		free(current);
}

char	*ft_strslice(char *src, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	if (src)
	{
		res = ft_calloc(end - start, sizeof(char));
		if (!res)
			return (NULL);
		while (start < end)
			res[i++] = src[start++];
		return (res);
	}
	return (NULL);
}

void	ft_add_flag(char *src, t_flag **flags)
{
	t_flag	*flag;
	t_flag	*current;

	if (*flags == NULL)
	{
		*flags = ft_calloc(NODE_SIZE, sizeof(t_flag));
		(*flags)->flag = src;
		(*flags)->next = NULL;
		(*flags)->prev = NULL;
	}
	else
	{
		//printf("115\n");
		//printf("%s\n", src);
		flag = ft_calloc(NODE_SIZE, sizeof(t_flag));
		current = *flags;
		while (current->next)
			current = current->next;
		flag->flag = src;
		flag->prev = current;
		flag->next = NULL;
		current->next = flag;
	}
}

int	ft_has_flags(char *src)
{
	int	i;

	i = -1;
	if (src)
	{
		while (src[++i])
		{
			if (src[i] == '-')
				return (CORRECT);
		}
	}
	return (INCORRECT);
}

int	ft_count_flags(char *src)
{
	int	i;
	int	flags;

	flags = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] == '-')
			flags++;
		i++;
	}
	return (flags);
}

//WIP changer flags et spaces par un char non affichable
void	ft_flag_op(t_flag **flags, char *cmd)
{
	char	*flag;
	int		flag_index;
	int		flag_count;
	int		space_index;

	space_index = ft_at_index(cmd, ' ');
	flag_index = ft_at_index(cmd, '-');
	flag_count = ft_count_flags(cmd);
	while (flag_count)
	{
		flag_count--;
		printf("flag index: %d\nspace index: %d\n", flag_index, space_index);
		flag = ft_strslice(cmd, flag_index, space_index);
		ft_add_flag(cmd, flags);
		printf("115\n");
		cmd[flag_index] = PASSED_THROUGH;
		cmd[space_index] = PASSED_THROUGH;
		flag_index = ft_at_index(cmd, '-');
		if (ft_at_index(cmd, ' ') == INVALID)
			space_index = ft_strlen(cmd);
		else
			space_index = ft_at_index(cmd, ' ');
	}
}

char	*ft_arg_op(char *cmd)
{
	char	*res;

	res = NULL;
	if (ft_at_index(cmd, '\'') != INVALID || ft_at_index(cmd, '"') != INVALID)
		;
	return (res);
}

int	ft_has_redirect(char *src)
{
	int	i;

	i = -1;
	if (src)
	{
		while (src[++i])
			if (src[i] == '<' || src[i] == '>')
				return (CORRECT);
	}
	return (INCORRECT);
}

int	ft_redirect_op(char *cmd)
{
	int	fd;

	fd = 0;
	(void) cmd;
	return (fd);
}

char	**ft_cmd_reconstruct(t_decon decon)
{
	int		i;
	char	**res;
	t_flag	*current;
	int		flag_count;

	i = 0;
	flag_count = ft_list_count(decon.flags);
	printf("flag count: %d\n", flag_count);
	res = ft_calloc(flag_count + REST_OF_CMD, sizeof(char *));
	if (!res)
		printf("oopsie daisy\n");
	current = decon.flags;
	res[i++] = decon.cmd;
	while (current->next)
	{
		res[i++] = current->flag;
		current = current->next;
	}
	res[i++] = current->flag;
	res[i] = decon.arg;
	return (res); 
}

//
/*char	**ft_cmd_deconstruct(char *cmd)
{
	t_decon decon;
	char	*temp;
	char	*current;
	int		cmd_index;
	int		space_index;

	if (ft_has_redirect(cmd))
		cmd_index = ft_redirect_op(cmd);
	else
		cmd_index = FIRST_INDEX;
	ft_bzero(&decon, sizeof(t_decon));
	decon.cmd = ft_strslice(cmd, cmd_index, ft_at_index(cmd, ' '));
	current = ft_strslice(cmd, ft_at_index(cmd, ' '), ft_strlen(cmd));
	if (ft_has_flags(current))
		space_index = ft_flag_op(&decon.flags, cmd);
	else
		space_index = ft_at_index(current, ' ');
	temp = current;
	current = ft_strslice(cmd, space_index, ft_strlen(cmd));
	free(temp);
	ft_arg_op(current);
	free(current);
	return (ft_cmd_reconstruct(decon));
}*/

char	**ft_cmd_deconstruct(char *cmd)
{
	if (ft_has_redirect(cmd))
		;
	if (ft_has_flags(cmd))
		;
	return (NULL);
}

void	ft_purge(char *first_cmd, char *sec_cmd)
{
	free(first_cmd);
	free(sec_cmd);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s\n", av[1]);
		int index1 = ft_at_index(av[1], '_');
		int index2 = ft_at_index(av[1], ' ');
		char *s1 = ft_strslice(av[1], index1, index2);
		char *s2 = ft_strslice(av[1], index2, ft_strlen(av[1]));
		printf("%s\n", s1);
		printf("%s\n", s2);
	}
	else
	{
		int i = 0;
		t_decon cmd;
		cmd.cmd = "ls";
		char *flag_test = "-l -a -a -a";
		t_flag *flags = NULL;
		//ft_add_flag("-l", &flags);
		//ft_add_flag("-a", &flags);
		//ft_add_flag("-a", &flags);
		//ft_add_flag("-a", &flags);
		ft_flag_op(&flags, );
		cmd.flags = flags;
		cmd.arg = ".";
		cmd.open_mark = 0;
		char **src = ft_cmd_reconstruct(cmd);
		while (src[i])
			printf("%s\n", src[i++]);
	}
	return (0);
}
