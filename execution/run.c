
#include "execution.h"

//126
static int	permission_denied(char *name)
{
	ft_printf(STDERR_FILENO, "%ominishell: %s: Permission denied\n", \
	NULL, name);
	return (126);
}

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
		return (err_msg(DO_FREE, 127, \
		ft_strjoin(MS_NAME ERR_CNF, in->command[0])));
	if (exe.err == NO_ASS)
		return (permission_denied(in->command[0]));
	exe.err_redir = set_redir(in);
	if (exe.err_redir < SUCCESS)
		return (exe.err_redir);
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
int	run_cmd(t_cmd *in, int *pec)
{
	t_run	run;

	ft_bzero(&run, sizeof(t_run));
	if (!in || !pec)
		return (BAD_ARGS);
	run.tmp = in;
	set_pipe(&in);
	while (run.tmp)
	{
		close_old_fd(run.tmp);
		if (run.tmp->tok && ft_b_flag_read(run.tmp->tok->mode, BUILT_IN))
			run.err = execution_builtin(run.tmp, &run.wait, cmd_node_len(in));
		else
			run.err = ft_execution(run.tmp, &run.wait);
		if (run.err == FAIL)
			err_msg(PERROR, run.err, "ft_execution");
		else
			*pec = run.err;
		run.tmp = run.tmp->next;
	}
	close_all_fd(in);
	wait_pids(run.wait, 1);
	cmd_free(&in);
	return (SUCCESS);
}
