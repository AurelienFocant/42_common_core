/* ************************************************************************** */
/*                                                                            */
/*   3_cmd.c                                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:59:16 by afocant           #+#    #+#             */
/*   Updated: 2025/03/26 13:38:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

extern int	g_signum;

static char	*absolute_path(char *cmd, t_shell *shell)
{
	struct stat	st;

	if (access(cmd, F_OK) != EXIT_SUCCESS)
		shell->flags |= ENOENT_CMD;
	else
	{
		if (access(cmd, X_OK) != EXIT_SUCCESS)
			shell->flags |= EACCES_CMD;
		else
		{
			stat(cmd, &st);
			if (st.st_mode & S_IFDIR)
				shell->flags |= ISDIR_CMD;
		}
	}
	return (cmd);
}

static char	*get_executable_name(char *cmd, t_shell *shell)
{
	char	*exec_name;

	exec_name = NULL;
	if (*cmd)
	{
		if (ft_strchr(cmd, '/'))
			exec_name = absolute_path(cmd, shell);
		else
			exec_name = search_path(cmd, shell);
	}
	else
	{
		shell->flags |= ENOENT_CMD;
		exec_name = cmd;
	}
	check_path_errors(exec_name, shell);
	return (exec_name);
}

static void	exec_child_process(t_cmd cmd, t_io *io, t_shell *shell)
{
	char	*exec_name;
	char	**env;

	reset_signals_default();
	if (cmd.redir)
		visit_node(cmd.redir, io, shell);
	duplicate_fds(io);
	if (!*cmd.name)
		exit(EXIT_SUCCESS);
	if (!(shell->flags & EACCES_FILE || shell->flags & ENOENT_FILE))
	{
		exec_name = get_executable_name(cmd.name[0], shell);
		env = strlst_to_strv(shell->envp);
		execve(exec_name, cmd.name, env);
		ft_dprintf(STDERR_FILENO, "execve failed !!\n");
		ft_free_null_strv(&env);
	}
	free_shell(shell);
	exit(EXIT_FAILURE);
}

void	visit_cmd(t_cmd *cmd, t_io *io, t_shell *shell)
{
	pid_t	pid;

	perform_expansions(&(cmd->name), shell);
	if (*cmd->name)
		if (is_builtin(cmd->name[0]))
			return (exec_builtin(*cmd, io, shell));
	pid = fork();
	if (pid == SYSCALL_ERROR)
	{
		write(2, "fork syscall error\n", 19);
		return ;
	}
	if (pid == CHILD)
		exec_child_process(*cmd, io, shell);
	shell->nb_of_children++;
	shell->last_child = pid;
	set_signals_waiting_parent();
}
