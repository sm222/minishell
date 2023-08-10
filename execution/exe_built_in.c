#include "execution.h"
#include "../readline/history.h"
#include "../readline/readline.h"

/// @brief	try to find the cmd adrres
/// @param	name	name of the cmd
/// @param	f		flag
/// @return			find the file in the local folder
static char	*find_built_in(char *name, int *f)
{
	char	*s;

	if (f && name)
	{
		*f = SUCCESS;
		ft_printf(-1, "%o%sft_%s", &s, PATH_BIN, name);
		if (s && access(s, F_OK | X_OK) == 0)
			return (s);
		ft_free(s);
		*f = FAIL;
		return (NULL);
	}
	else if (f)
		*f = BAD_ARGS;
	return (NULL);
}

/// @brief	return the addres of the built in
/// @param	name	char* name of the cmd you look for
/// @return	void* of the ft
static void	*find_built_in_l(char *name)
{
	if (ft_strncmp(name, ECHO, ft_strlen(ECHO) + 1) == 0)
		return (&ft_echo);
	if (ft_strncmp(name, PWD, ft_strlen(PWD) + 1) == 0)
		return (&ft_pwd);
	if (ft_strncmp(name, CD, ft_strlen(CD) + 1) == 0)
		return (&ft_cd);
	if (ft_strncmp(name, EXIT, ft_strlen(EXIT) + 1) == 0)
		return (&ft_exit);
	if (ft_strncmp(name, ENV, ft_strlen(ENV) + 1) == 0)
		return (&ft_env);
	if (ft_strncmp(name, UNSET, ft_strlen(UNSET) + 1) == 0)
		return (&ft_unset);
	if (ft_strncmp(name, EXPORT, ft_strlen(EXPORT) + 1) == 0)
		return (&ft_export);
	return (NULL);
}

/// @brief	chnage the argument for exit and env
/// @param	in		input t_cmd*
/// @param	local	if it run in the fork or not
static void	change_arg(t_cmd *in)
{
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (!shell)
		err_msg(NO_FREE, 1, "rt_ptr");
	if (ft_strncmp(in->command[0], EXIT, ft_strlen(EXIT) + 1) == 0)
	{
		change_name(shell->pec, in);
	}
	if (ft_strncmp(in->command[0], ENV, ft_strlen(ENV) + 1) == 0)
		if (change_av_for_en(in) < SUCCESS)
			err_msg(PERROR, M_FAIL, "change_av_for_en");
	if (ft_strncmp(in->command[0], PWD, ft_strlen(PWD) + 1) == 0)
		if (change_av_pwd(in, shell->info) < SUCCESS)
			err_msg(PERROR, M_FAIL, "change_av_pwd");
}

/// @brief	use to run a built in
/// @param	ft	address of the function
/// @param	in	t_cmd* data of the function
/// @return	return the err code of the function
static int	run_local(int (*ft)(char **, int, int, char **), t_cmd *in)
{
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (!ft)
		return (FAIL);
	change_arg(in);
	shell->pec = \
	ft(in->command, in->tok->redi_in, in->tok->redi_out, shell->en);
	if (ft == &ft_cd)
		change_env_data(shell);
	if (shell->exit)
	{
		cmd_free(&in);
		free_t_mshell(shell);
		rl_clear_history();
		ft_putstr_fd("exit\n", 1);
		exit(((unsigned char)shell->pec));
	}
	shell->en = ft_return_ptr(NULL, ENV_C);
	return (SUCCESS);
}

/// @brief	take a cmd and redirect it to a buildin,
/// @brief	if can't find it try to run a bash one
/// @param	in		t_cmd* input
/// @param	wait	t_waitp* address of the list of pid
/// @param	cmd_len	len of the number of cmd
/// @return	err code
int	execution_builtin(t_cmd *in, t_waitp **wait, int cmd_len)
{
	int		f;
	char	*name;

	name = NULL;
	if (cmd_len > 1)
	{
		name = find_built_in(in->command[0], &f);
		if (!name && f == SUCCESS)
			return (err_msg(NO_FREE, M_FAIL, MS_NAME \
				"Malloc fail : ft_execution_buildin"));
		if (f != FAIL)
		{
			ft_free(in->command[0]);
			in->command[0] = name;
		}
		change_arg(in);
		return (ft_execution(in, wait));
	}
	else if (cmd_len == 1)
	{
		if (run_local(find_built_in_l(in->command[0]), in) == FAIL)
			return (ft_execution(in, wait));
		return (SUCCESS);
	}
	return (FAIL);
}
