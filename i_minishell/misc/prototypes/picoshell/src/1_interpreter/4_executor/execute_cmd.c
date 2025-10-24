#include "picoshell.h"

t_exit_code	execute_cmd(t_cmd cmdnode, t_ctxt *ctxt, t_shell *shell)
{
	char	*cmd;
	t_exit_code	exit_code;

	if (cmdnode.next)
		execute_node(cmdnode.next, ctxt, shell);
	cmd = cmdnode.string;
	exit_code = fork_exec(cmd, cmdnode, ctxt, shell);
	return (exit_code);
}

void	execute_builtin(char *cmd, t_shell *shell)
{
	if (ft_strcmp(cmd, "exit") == EXIT_SUCCESS)
			ft_exit(shell->last_exit_code);
}

bool	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "exit") == EXIT_SUCCESS)
		return (true);
	return (false);
}

t_exit_code	fork_exec(char *exec_path, t_cmd cmdnode, t_ctxt *ctxt, t_shell *shell)
{
	pid_t	pid;
	char	**cmd;
	int		exit_status;

	if (is_builtin(cmdnode.string))
		execute_builtin(cmdnode.string, shell);
	else
		cmd = ft_split(cmdnode.string, ' ');
	// should save cmd as char ** in cmd node ?

	(void) shell;
	(void) exec_path;
	pid = fork();
	if (pid == 0)
	{
		if (ctxt->to_close != NO_FILE)
			close(ctxt->to_close);
		duplicate_fd(ctxt);	
		execve(cmd[0], cmd, cmd);
		dprintf(2, "exec failed\n");
		exit(127);
	}
	wait(&exit_status);
	return (WEXITSTATUS(exit_status));
}
