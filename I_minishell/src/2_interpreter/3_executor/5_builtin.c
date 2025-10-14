/* ************************************************************************** */
/*                                                                            */
/*   4_builtin.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:15:35 by afocant           #+#    #+#             */
/*   Updated: 2025/03/26 13:38:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

bool	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == EXIT_SUCCESS)
		return (true);
	if (ft_strcmp(cmd, "pwd") == EXIT_SUCCESS)
		return (true);
	if (ft_strcmp(cmd, "exit") == EXIT_SUCCESS)
		return (true);
	if (ft_strcmp(cmd, "env") == EXIT_SUCCESS)
		return (true);
	if (ft_strcmp(cmd, "export") == EXIT_SUCCESS)
		return (true);
	if (ft_strcmp(cmd, "unset") == EXIT_SUCCESS)
		return (true);
	if (ft_strcmp(cmd, "echo") == EXIT_SUCCESS)
		return (true);
	return (false);
}

static t_exit_code	execute_builtin(t_cmd cmd, t_shell *shell)
{
	if (ft_strcmp(cmd.name[0], "cd") == EXIT_SUCCESS)
		return (cd_builtin(cmd, shell));
	if (ft_strcmp(cmd.name[0], "pwd") == EXIT_SUCCESS)
		return (pwd_builtin(shell));
	if (ft_strcmp(cmd.name[0], "exit") == EXIT_SUCCESS)
		return (exit_builtin(cmd, shell));
	if (ft_strcmp(cmd.name[0], "env") == EXIT_SUCCESS)
		return (env_builtin(shell));
	if (ft_strcmp(cmd.name[0], "export") == EXIT_SUCCESS)
		return (export_builtin(cmd, shell));
	if (ft_strcmp(cmd.name[0], "unset") == EXIT_SUCCESS)
		return (unset_builtin(cmd, shell));
	if (ft_strcmp(cmd.name[0], "echo") == EXIT_SUCCESS)
		return (echo_builtin(cmd));
	return (EXIT_FAILURE);
}

static void	forked_builtin(t_cmd cmd, t_io *io, t_shell *shell)
{
	if (cmd.redir)
		visit_node(cmd.redir, io, shell);
	duplicate_fds(io);
	if (!(shell->flags & EACCES_FILE || shell->flags & ENOENT_FILE))
		shell->exit_code = execute_builtin(cmd, shell);
	free_and_exit_shell(NULL, shell->exit_code, shell);
}

void	exec_builtin(t_cmd cmd, t_io *io, t_shell *shell)
{
	pid_t	pid;

	if (shell->flags & HAS_PIPE)
	{
		pid = fork();
		if (pid == SYSCALL_ERROR)
		{
			write(2, "fork syscall error\n", 19);
			return ;
		}
		shell->nb_of_children++;
		shell->last_child = pid;
		if (pid == CHILD)
			forked_builtin(cmd, io, shell);
	}
	else
	{
		if (cmd.redir)
			visit_node(cmd.redir, io, shell);
		duplicate_fds(io);
		if (!(shell->flags & EACCES_FILE || shell->flags & ENOENT_FILE))
			shell->exit_code = execute_builtin(cmd, shell);
	}
}
