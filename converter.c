#include "include/minishell.h"

static int	find_buit_in(char *name)
{
	int		flag;
	char	*tmp;
	size_t	i;

	flag = 0;
	i = 0;
	tmp = ft_strdup(name);
	if (!tmp)
		return (flag);
	while (tmp[i])
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	if (ft_strncmp(tmp, ECHO, ft_strlen(ECHO) + 1) == 0 || \
		ft_strncmp(tmp, PWD, ft_strlen(PWD) + 1) == 0 || \
		ft_strncmp(tmp, CD, ft_strlen(CD) + 1) == 0 || \
		ft_strncmp(tmp, EXIT, ft_strlen(EXIT) + 1) == 0 || \
		ft_strncmp(tmp, ENV, ft_strlen(ENV) + 1) == 0 || \
		ft_strncmp(tmp, UNSET, ft_strlen(UNSET) + 1) == 0 || \
		ft_strncmp(tmp, EXPORT, ft_strlen(EXPORT) + 1) == 0)
		flag = BUILT_IN_FLAG;
	free(tmp);
	return (flag);
}

short	converter(char *in, t_cmd **list)
{
	t_loc	*tmp;
	t_loc	*nav;
	int		flag;

	if (!in || !list)
		return (BAD_ARGS);
	nav = ft_parsing(in);
	while (nav)
	{
		flag = 0;
		if (nav->decon_cmd && nav->decon_cmd[0])
			flag = find_buit_in(nav->decon_cmd[0]);
		cmd_make_node_last(list, nav->decon_cmd, make_token(flag, 0, 0));
		tmp = nav;
		nav = nav->next;
		ft_free(tmp);
	}
	return (SUCCESS);
}
