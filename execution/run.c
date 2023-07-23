
#include "execution.h"

/// @brief	use to run the cmd (need to add stuff)
/// @param	in		t_cmd link list
/// @param	path	env of system
/// @param	cmd		relatif path of the cmd ex: /bin/ls
/// @return
int	run_and_close(t_cmd *in, char **env, char *cmd)
{
	int			err;
	t_mshell	*shell;

	(void)err;
	shell = NULL;
	dup_in_out(in);
	close_all_fd(in);
	if (in->tok->redi_in != -1)
		err = execve(cmd, in->command, env);
	ft_free(cmd);
	cmd_free(&in);
	shell = ft_return_ptr(NULL, SYS);
	cmd_free(&in);
	ft_double_sfree((void **)shell->path);
	ft_double_sfree((void **)shell->en);
	ft_free(shell->s);
	ft_free(shell->tmp);
	ft_free(shell->info);
	exit(ENOTRECOVERABLE);
	return (FAIL);
}

/// @brief	use to find the cmd and run it
/// @param	in		t_cmd to run
/// @param	wait	adrres of the 't_waip' list
/// @return	FORK_FAIL if fork did't work
/// @return	FAIL if can't find a cmd,
/// @return	else SUCCESS
short	ft_execution(t_cmd *in, t_waitp **wait)
{
	t_exe		exe;
	t_mshell	*shell;

	shell = ft_return_ptr(NULL, SYS);
	if (!shell || !in || !wait)
		return (BAD_ARGS);
	exe.err = find_path(in->command[0], &exe.ft_path, shell->path);
	if (exe.err == FAIL)
		err_msg(DO_FREE, exe.err, ft_strjoin(MS_NAME ERR_CNF, in->command[0]));
	if (set_redir(in) <= FAIL)
		return (FAIL);
	else if (exe.err == M_FAIL)
		return (M_FAIL);
	exe.pid = fork();
	if (exe.pid == -1)
		return (err_msg(NO_FREE, FORK_FAIL, "fork fail"));
	if (exe.pid == 0)
		run_and_close(in, shell->en, exe.ft_path);
	else
		wait_make_node_last(wait, exe.pid);
	ft_free(exe.ft_path);
	return (SUCCESS);
}

/// @brief	use after 'cmd_make_node_last'
/// @param	in	t_cmd list of cmd 't_cmd *'
/// @return	BAD_ARGS, else SUCCESS
int	run_cmd(t_cmd *in)
{
	int		err;
	t_waitp	*wait;
	t_cmd	*tmp;

	wait = NULL;
	if (!in)
		return (BAD_ARGS);
	tmp = in;
	err = 0;
	set_pipe(&in);
	while (tmp)
	{
		close_old_fd(tmp);
		if (tmp->tok && ft_b_flag_read(tmp->tok->mode, BUILT_IN))
			err = ft_execution_built_in(tmp, &wait, cmd_node_len(in));
		else
			err = ft_execution(tmp, &wait);
		if (err < SUCCESS)
			err_msg(PERROR, err, "ft_execution");
		tmp = tmp->next;
	}
	close_all_fd(in);
	wait_pids(wait, 1);
	cmd_free(&in);
	return (SUCCESS);
}
