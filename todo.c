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

// NEEDS TESTING
void	ft_add_slice(char *src, t_decon **decon)
{
	t_decon	*current;
	t_decon	*dc;

	if (*decon == NULL)
	{
		*decon = ft_calloc(NODE_SIZE, sizeof(t_flag));
		(*decon)->src = src;
		(*decon)->next = NULL;
	}
	else
	{
		dc = ft_calloc(NODE_SIZE, sizeof(t_flag));
		current = *decon;
		while (current->next)
			current = current->next;
		dc->src = src;
		dc->next = NULL;
		current->next = dc;
	}
}

int	ft_has_quote(char *src)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		if (src[i] == '"' || src[i] == '\'')
			return (CORRECT);
	}
	return (INCORRECT);
}

int	ft_has_meta(char *src)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		if (src[i] == '$')
			return (CORRECT);
	}
	return (INCORRECT);
}

// WIP
char	*ft_meta_op()
{
	char	**env;
	
	env = ft_return_ptr(NULL, ENV_C);
}

// WIP
int	ft_quote_op(char *src, int index)
{
	int	open_mark;
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '"')
		{
			if (ft_has_meta(src))
				ft_meta_op();
		}
		i++;
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

// NEED TESTING
char	**ft_cmd_reconstruct(t_decon decon)
{
	int		i;
	char	**res;
	t_decon	*current;
	int		flag_count;

	i = 0;
	count = ft_list_count(decon);
	current = &decon;
	res = ft_calloc(count, sizeof(char *));
	if (!res)
	{
		ft_printf("malloc fail");
		return (NULL);
	}
	while (current)
	{
		res[i++] = current->src;
		current = current->next;
	}
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

// WIP
t_decon	ft_cmd_deconstruct(char *cmd)
{
	char	*current_slice;
	int		start_index;
	int		end_index;
	t_decon	decon;

	if (!cmd)
	{
		ft_printf("");
		return (NULL);
	}
	start_index = FIRST_INDEX;
	end_index = ft_at_index(cmd, ' ');
	while (end_index != ft_strlen(cmd) || \
			end_index != ft_at_rev_index(cmd, PASSED_THROUGH))
	{
		current_slice = ft_strslice(cmd, start_index, end_index);
		if (ft_has_quote(current_slice))
			current_slice = ft_quote_op(current_slice);
		ft_add_slice(current_slice, &decon);
		if (ft_has_redirect(cmd))
		{
			if ()
		}
		start_index = ft_at_index(cmd + end_index, ' ') + end_index;
		end_index = ft_at_index(cmd + start_index. ' ') + start_index;
	}
	return (decon);
}

// NEEDS TESTING
void	ft_purge(t_decon *decon)
{
	t_decon	*current;

	current = decon;
	while (current)
	{
		free(current->src);
		current = current->next;
	}
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
		char *cmd = "ls -laal ..";
		t_decon decon = ft_cmd_deconstruct(cmd);
		char **src = ft_cmd_reconstruct(decon);
		while (src[i])
			printf("%s\n", src[i++]);
	}
	return (0);
}
