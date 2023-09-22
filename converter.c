#include "include/minishell.h"

static int	find_buit_in(char *name)
{
	int	flag;
	
	flag = 0;
	if (ft_strncmp(name, ECHO, ft_strlen(ECHO) + 1) == 0)
		flag = BUILT_IN_FLAG;
	if (ft_strncmp(name, PWD, ft_strlen(PWD) + 1) == 0)
		flag = BUILT_IN_FLAG;
	if (ft_strncmp(name, CD, ft_strlen(CD) + 1) == 0)
		flag = BUILT_IN_FLAG;
	if (ft_strncmp(name, EXIT, ft_strlen(EXIT) + 1) == 0)
		flag = BUILT_IN_FLAG;
	if (ft_strncmp(name, ENV, ft_strlen(ENV) + 1) == 0)
		flag = BUILT_IN_FLAG;
	if (ft_strncmp(name, UNSET, ft_strlen(UNSET) + 1) == 0)
		flag = BUILT_IN_FLAG;
	if (ft_strncmp(name, EXPORT, ft_strlen(EXPORT) + 1) == 0)
		flag = BUILT_IN_FLAG;
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
		tmp = nav->next;
		ft_free(nav);
		nav = tmp;
	}
	return (SUCCESS);
}
