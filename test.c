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

int	ft_list_count(t_decon *head)
{
	int		i;
	t_decon	*current;

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

void	ft_add_slice(char *src, t_decon *decon)
{
	t_decon	*current;
	t_decon	*dc;

	if (decon == NULL)
	{
		decon = ft_calloc(NODE_SIZE, sizeof(t_decon));
		decon->src = src;
		decon->next = NULL;
	}
	else
	{
		dc = ft_calloc(NODE_SIZE, sizeof(t_decon));
		current = decon;
		while (current->next)
			current = current->next;
		dc->src = src;
		dc->next = NULL;
		current->next = dc;
	}
}

char	**ft_cmd_reconstruct(t_decon decon)
{
	int		i;
	char	**res;
	t_decon	*current;
	int		count;

	i = 0;
	count = ft_list_count(&decon);
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

t_decon	ft_cmd_deconstruct(char *cmd)
{
	char	*current_slice;
	size_t	start_index;
	size_t	end_index;
	t_decon	decon;

	ft_bzero(&decon, sizeof(t_decon));
	if (!cmd)
	{
		ft_printf("");
		return (decon);
	}
	start_index = FIRST_INDEX;
	end_index = ft_at_index(cmd, ' ');
	while (end_index != ft_strlen(cmd) || \
			end_index != (size_t)ft_at_rev_index(cmd, PASSED_THROUGH))
	{
		current_slice = ft_strslice(cmd, start_index, end_index);
		//if (ft_has_quote(current_slice))
		//	current_slice = ft_quote_op(current_slice);
		ft_add_slice(current_slice, &decon);
		//if (ft_has_redirect(cmd))
		{
		}
		start_index = ft_at_index(cmd + end_index, ' ') + end_index;
		end_index = ft_at_index(cmd + start_index, ' ') + start_index;
	}
	return (decon);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char **src = ft_cmd_reconstruct(ft_cmd_deconstruct(av[1]));
		int i = 0;
		while (src[i])
		{
			ft_printf("%s\n", src[i]);
			i++;
		}
	}
}
