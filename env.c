#include "minishell.h"

/// @brief make the path double array in 'data->path'
/// @param data take 'mshell' struct
/// @return FAIL if can't find 'PATH='
/// @return if split fail
/// @return else SUCCESS
int	get_env_path(t_mshell *data)
{
	size_t	i;

	i = 0;
	//Ct_debug(0, "test", 0, FILE_DEF);
	//Ct_debug_pro(0, FILE_DEF, 0, "this is a test %s %d", "ah", 9754);
	while (data->en[i])
	{
		if (ft_strncmp(data->en[i], "PATH=", 5) == 0)
		{
			data->path = ft_split(data->en[i], ':');
			if (!data->path)
				return (M_FAIL);
			return (SUCCESS);
		}
		i++;
	}
	return (FAIL);
}
