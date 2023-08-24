#include "parsing.h"

int	ft_suffix(char **cmd)
{
}

int ft_prefix(char **cmd)
{
}

// WIP
int	ft_redirect_op(char **cmd, t_token *tokens)
{
	int	prefix_index;
	int	suffix_index;
	int	redirect_index;

	redirect_index = ft_redirect_index();
	if (redirect_index != INVALID && redirect_index == FIRST_INDEX)
		ft_prefix(cmd);
	if (redirect_index != INVALID && redirect_index > FIRST_INDEX)
		ft_suffix(cmd);
	prefix_index = ft_at_index(cmd, PASSED_PREFIX);
	suffix_index = ft_at_index(cmd, PASSED_SUFFIX);
	if (prefix_index != INVALID && suffix_index != INVALID)
	{
		(*cmd)[prefix_index] = PASSED_THROUGH;
		(*cmd)[suffix_index] = PASSED_THROUGH;
	}

}

