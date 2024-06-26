/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:26:14 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/20 21:29:12 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
//#include "../readline/readline.h"

//126
//is a directory
int	permission_denied(char *name, mode_t *err, int code)
{
	if (S_ISDIR(*err) || S_ISLNK(*err))
	{
		ft_printf(STDERR_FILENO, "%o"MS_NAME"\b %s: %s\n", \
		NULL, name, ISDIR);
	}
	else if (code == NO_ASS)
	{
		ft_printf(STDERR_FILENO, "%o"MS_NAME"\b %s: %s\n", \
		NULL, name, strerror(errno));
		return (126);
	}
	else if (code == ERR_PD)
	{
		ft_printf(STDERR_FILENO, "%o"MS_NAME"\b %s: %s\n", \
		NULL, name, strerror(errno));
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
	int	err;

	err = 127;
	if (name && (name[0] == '/'))
	{
		if (errno == 20)
			err = 126;
		ft_printf(STDERR_FILENO, "%o"MS_NAME"\b: %s %s\n", \
		NULL, name, strerror(errno));
		return (err);
	}
	ft_printf(2, "%o"MS_NAME"\b "ERR_CNF"%s\n", NULL, name);
	return (127);
}

/// @brief	use to run the cmd (need to add stuff)
/// @param	in		t_cmd link list
/// @param	path	env of system
/// @param	cmd		relatif path of the cmd ex: /bin/ls
/// @return
int	run_and_close(t_cmd *in, char **env, char *cmd)
{
	t_mshell	*shell;
	char		**new_en;
	void		(*ft)(int);
	int			err;

	free_and_dup_in_run(in);
	new_en = NULL;
	err = 0;
	shell = ft_return_ptr(NULL, SYS);
	ft = ft_return_ptr(NULL, SIG);
	ft(CHILD);
	rl_clear_history();
	if (in->command)
	{
		new_en = ex_en_new(env);
		err = execve(cmd, in->command, new_en);
		perror("minishell");
	}
	free_execution(&shell->cmd_list, shell);
	ft_free(cmd);
	ft_double_sfree((void **)new_en);
	exit(err);
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
	shell->keep_wait = *wait;
	err = set_data_exe(&exe, shell, in);
	if (err != SUCCESS)
		return (wait_make_node_last(wait, -1, err, NULL), SUCCESS);
	exe.pid = fork();
	if (exe.pid == -1)
		return (err_msg(NO_FREE, FORK_FAIL, "fork fail"));
	if (exe.pid == 0)
		(void)run_and_close(in, shell->en, exe.ft_path);
	else
	{
		if (in->command)
			wait_make_node_last(wait, exe.pid, local, ft_strdup(in->command[0]));
		else
			wait_make_node_last(wait, exe.pid, local, NULL);
	}
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
	while (run.tmp && run.tmp->tok)
	{
		close_old_fd(run.tmp);
		if (run.tmp->tok && ft_b_flag_read(run.tmp->tok->mode, BUILT_IN))
			run.err = execution_builtin(run.tmp, &run.wait, cmd_node_len(in));
		else
			run.err = ft_execution(run.tmp, &run.wait, 0);
		if (run.err <= FAIL)
			err_msg(PERROR, run.err, "minishell: ft_execution");
		run.tmp = run.tmp->next;
	}
	close_all_fd(in);
	cmd_free(&in);
	shell->cmd_list = NULL;
	return (wait_pids(run.wait, 1));
}
