
#include "execution.h"

//126
//is a directory
int	permission_denied(char *name, mode_t *err)
{
	if (S_ISDIR(*err) || S_ISLNK(*err))
	{
		ft_printf(STDERR_FILENO, "%ominishell: %s: %s\n", \
		NULL, name, ISDIR);
	}
	else if (*err == 1)
	{
		ft_printf(STDERR_FILENO, "%ominishell: %s: %s\n", \
		NULL, name, sys_errlist[errno]);
		return (126);
	}
	return (126);
}

/*
bash: ./awdawdawd: No such file or directory
bash-3.2$ /bin/lslsls
bash: /bin/lslsls: No such file or directory
bash-3.2$ asdasd
*/
int	no_file(char *name)
{
	if (name && (name[0] == '.' || name[0] == '/'))
		return (err_msg(DO_FREE, 126, ft_strjoin(MS_NAME ERR_NSFD, name)));
	err_msg(DO_FREE, 127, ft_strjoin(MS_NAME ERR_CNF, name));
	return (127);
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

	err = 0;
	ex_en_new(env);
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

/*
	refactor and add a new node with the err code in it if fail
	ex: if permission_denied , make node with no pid and 126 err code
*/
/// @brief	use to find the cmd and run it
/// @param	in		t_cmd to run
/// @param	wait	adrres of the 't_waip' list
/// @return	FORK_FAIL if fork did't work
/// @return	FAIL if can't find a cmd,
/// @return	else SUCCESS
short	ft_execution(t_cmd *in, t_waitp **wait, short local)
{
	t_exe		exe;
	t_mshell	*shell;
	int			err;

	shell = ft_return_ptr(NULL, SYS);
	if (!shell || !in || !wait)
		return (BAD_ARGS);
	err = set_data_exe(&exe, shell, in);
	if (err != SUCCESS)
	{
		wait_make_node_last(wait, -1, err);
		return (SUCCESS);
	}
	exe.pid = fork();
	if (exe.pid == -1)
		return (err_msg(NO_FREE, FORK_FAIL, "fork fail"));
	if (exe.pid == 0)
		run_and_close(in, shell->en, exe.ft_path);
	else
		wait_make_node_last(wait, exe.pid, local);
	ft_free(exe.ft_path);
	return (SUCCESS);
}

/// @brief	use after 'cmd_make_node_last'
/// @param	in	t_cmd list of cmd 't_cmd *'
/// @return	BAD_ARGS, else SUCCESS
int	run_cmd(t_cmd *in, t_mshell *shell)
{
	t_run	run;

	ft_bzero(&run, sizeof(t_run));
	if (!in || !shell)
		return (BAD_ARGS);
	run.tmp = in;
	if (make_new_path(shell) < SUCCESS)
		perror("make_new_path");
	set_pipe(&in);
	while (run.tmp)
	{
		close_old_fd(run.tmp);
		if (run.tmp->tok && ft_b_flag_read(run.tmp->tok->mode, BUILT_IN))
			run.err = execution_builtin(run.tmp, &run.wait, cmd_node_len(in));
		else
			run.err = ft_execution(run.tmp, &run.wait, 0);
		if (run.err <= FAIL)
			err_msg(PERROR, run.err, "ft_execution");
		run.tmp = run.tmp->next;
	}
	close_all_fd(in);
	wait_pids(run.wait, 1);
	cmd_free(&in);
	return (SUCCESS);
}
