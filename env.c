#include "minishell.h"

int	get_env_path(t_mshell *data)
{
	size_t	i;
	int		err;

	i = 0;
	while (data->en[i])
	{
		if (ft_strncmp(data->en[i], "PATH=", 5) == 0)
		{
			data->path = ft_split(data->en[i], ':');
			if (!data->path)
				err = M_FAIL;
			else
				err = 1;
			break ;
		}
		err = FAIL;
	}
	return (err);
}