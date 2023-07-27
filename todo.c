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
			current = current->next;
			i++;
		}
		i++;
	}
	return (i);
}

// NEED TESTING
void	ft_pipe_op(char *cmd)
{
	int		pipe_index;
	char	*full_cmd;
	char	*current;
	char	*temp;

	current = ft_strdup(cmd);
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

// NEED TESTING
int	ft_end_flag(char *src, int start)
{
	int	end;

	while (ft_at_index(src + start, '-') != INVALID)
		start = ft_at_index(src + start, '-') + start;
	end = ft_at_index(src + start, ' ') + start;
	return (end);
}

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
		ft_add_flag(flag, flags);
		cmd[flag_index] = PASSED_THROUGH;
		cmd[space_index] = PASSED_THROUGH;
		flag_index = ft_at_index(cmd, '-');
		if (ft_at_index(cmd, ' ') == INVALID)
			space_index = ft_strlen(cmd);
		else
			space_index = ft_at_index(cmd, ' ');
	}
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

// NEED TESTING
char	*ft_get_file(char *cmd, char mode)
{
	char	*res;
	int		mode_index;
	int		space_start;
	int		space_end;

	res = NULL;
	if (mode == 'o')
	{
		mode_index = ft_at_index(cmd, '>');
		space_start = ft_at_index(cmd + mode_index, ' ') + mode_index;
		if (ft_at_index(cmd + space_start, ' '))
			space_end = ft_at_index(cmd + space_start, ' ') + space_start;
		else
			space_end = ft_strlen(cmd);
		res = ft_strslice(cmd, space_start, space_end);
	}
	else if (mode == 'i')
	{
		space_end = ft_at_index(cmd, ' ');
		res = ft_strslice(cmd, FIRST_INDEX, space_end);
	}
	return (res);
}

// NEED TESTING
int	ft_file_op(char *cmd, char redirect, char mode)
{
	int		fd;
	int		redirect_index;
	char	*file_path;

	redirect_index = ft_at_index(cmd, redirect);
	file_path = ft_get_file(cmd, mode);
	if (cmd[redirect_index + 1] == redirect)
	{
		fd = open(file_path, O_APPEND);
	}
	else
	{
		fd = open(file_path, O_CREAT);
	}
	return (fd);
}

// NEED TESTING
t_token	ft_redirect_op(char *cmd)
{
	t_token	token;

	if (ft_at_index(cmd, '<') != INVALID)
		token.redi_in = ft_file_op(cmd, '<', 'i');
	if (ft_at_index(cmd, '>') != INVALID)
		token.redi_out = ft_file_op(cmd, '>', 'o');
	return (token);
}

char	**ft_cmd_reconstruct(t_decon decon)
{
	int		i;
	char	**res;
	t_flag	*current;
	int		flag_count;

	i = 0;
	flag_count = ft_list_count(decon.flags);
	res = ft_calloc(flag_count + REST_OF_CMD, sizeof(char *));
	if (!res)
		printf("oopsie daisy\n"); //gérer les malloc fail
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

// NEED TESTING
char	*ft_cmd_op(char *cmd)
{
	int		start_index;
	int		end_index;
	char	*res;

	if (ft_at_index(cmd, '<') != INVALID)
	{
		start_index = ft_at_index(cmd, '<');
		start_index = ft_at_index(cmd + start_index, ' ') + start_index;
		end_index = ft_at_index(cmd + start_index, ' ') + start_index;
	}
	else
	{
		start_index = FIRST_INDEX;
		end_index = ft_at_index(cmd, ' ');
	}
	res = ft_strslice(cmd, start_index, end_index);
	return (res);
}

// NEED TESTING
char	*ft_arg_op(char *cmd)
{
	int		start_index;
	int		end_index;
	char	*res;

	res = NULL;
	if (ft_at_index(cmd, '\'') != INVALID || ft_at_index(cmd, '"') != INVALID)
		start_index = ft_at_index(cmd, '"');
	else
		start_index = ft_at_rev_index(cmd, ' ');
	if (ft_at_index(cmd, '>') != INVALID)
		end_index = ft_at_index(cmd, '>') - 1;
	else
		end_index = ft_strlen(cmd);
	res = ft_strslice(cmd, start_index, end_index);
	return (res);
}

// NEED TESTING
char	**ft_cmd_deconstruct(char *cmd)
{
	char	*flag_slice;
	int		start_index;
	int		end_index;
	t_decon	decon;
	
	decon.flags = NULL;
	if (ft_has_redirect(cmd))
		decon.token = ft_redirect_op(cmd);
	decon.cmd = ft_cmd_op(cmd);
	if (ft_has_flags(cmd))
	{
		start_index = ft_at_index(cmd, '-');
		if (ft_at_index(cmd + start_index, '-') != INVALID)
			end_index = ft_end_flag(cmd, start_index);
		else
			end_index = ft_at_index(cmd + start_index, ' ');
		flag_slice = ft_strslice(cmd, start_index, end_index);
		ft_flag_op(&decon.flags, flag_slice);
	}
	decon.arg = ft_arg_op(cmd);
	return (NULL);
}

// WIP
void	ft_purge(t_decon *decon)
{
	free(decon->cmd);
	//free flags
	free(decon->arg);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s\n", av[1]);
		char *s1 = ft_strslice(av[1], FIRST_INDEX, ft_at_index(av[1], '>') - 1);
		printf("%s\n", s1);
	}
	else
	{
		int i = 0;
		t_decon cmd;
		cmd.cmd = "ls";
		char *flag_test = "-l -a -a -a";
		t_flag *flags = NULL;
		ft_flag_op(&flags, ft_strslice(flag_test, FIRST_INDEX, ft_strlen(flag_test)));
		cmd.flags = flags;
		cmd.arg = ".";
		cmd.open_mark = 0;
		char **src = ft_cmd_reconstruct(cmd);
		while (src[i])
			printf("%s\n", src[i++]);
	}
	return (0);
}
