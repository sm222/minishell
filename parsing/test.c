#include "parsing.h"

char	**ft_cmd_reconstruct(t_decon *decon)
{
	int		i;
	char	**res;
	t_decon	*current;
	int		count;

	i = 0;
	count = ft_list_count(decon);
	current = decon;
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

void	ft_cmd_op(t_decon **decon, char *cmd, int start_index, int end_index)
{
	int		current_index;
	char	*current_slice;

	current_index =  ft_at_index(cmd + start_index, ' ');
	while (current_index < end_index)
	{
		current_slice = ft_strslice(cmd, start_index, current_index);
		ft_add_slice(current_slice, decon);
		start_index = end_index;
		if (ft_at_index(cmd + start_index, ' ') != INVALID)
			current_index = ft_at_index(cmd + start_index, ' ') + start_index;
		else
			current_index = ft_strlen(cmd);
	}
	current_slice = ft_strslice(cmd, start_index, current_index);
	ft_add_slice(current_slice, decon);
}

t_decon	*ft_cmd_deconstruct(char *cmd)
{
	size_t	start_index;
	size_t	end_index;
	t_decon	*decon;
	t_token	*tokens;

	decon = NULL;
	ft_bzero(tokens, sizeof(t_token));
	if (!cmd)
	{
		ft_printf("");
		return (decon);
	}
	start_index = FIRST_INDEX;
	end_index = ft_redirect_op(cmd, *token);
	ft_cmd_op(&decon, cmd, start_index, end_index);
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
