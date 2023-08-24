#include "parsing.h"

int	ft_at_index(char *src, char c)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
			if (src[i++] == c)
				return (i);
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
				return (i);
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

void	ft_add_slice(char *src, t_decon **decon)
{
	t_decon	*current;
	t_decon	*dc;

	if (*decon == NULL)
	{
		*decon = ft_calloc(NODE_SIZE, sizeof(t_decon));
		(*decon)->src = src;
		(*decon)->next = NULL;
	}
	else
	{
		dc = ft_calloc(NODE_SIZE, sizeof(t_decon));
		current = *decon;
		while (current->next)
			current = current->next;
		dc->src = src;
		dc->next = NULL;
		current->next = dc;
	}
}
