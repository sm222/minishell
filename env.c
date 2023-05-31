#include "minishell.h"

int	get_env_path(t_mshell *data)
{
	size_t	i;
	int		error;

	i = 0;
	while (data->en[i])
	{
		if (ft_strncmp(data->en[i], "PATH=", 5) == 0)
		{
			data->path = ft_split(data->en[i], ':');
			if (!data->path)
				error = M_FAIL;
			else
				error = 1;
			break ;
		}
		error = FAIL;
		i++;
	}
	return (error);
}
