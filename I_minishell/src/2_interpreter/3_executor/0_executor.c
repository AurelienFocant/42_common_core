/* ************************************************************************** */
/*                                                                            */
/*   0_executor.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:32:03 by afocant           #+#    #+#             */
/*   Updated: 2025/03/26 13:38:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"
#include "executor.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

extern int	g_signum;

t_exit_code	wait_for_children(t_shell *shell)
{
	int		wstatus;
	pid_t	pid;

	while (shell->nb_of_children)
	{
		pid = wait(&wstatus);
		if (pid == shell->last_child)
		{
			if (WIFEXITED(wstatus))
				shell->exit_code = WEXITSTATUS(wstatus);
			else if (WIFSIGNALED(wstatus))
			{
				g_signum = WTERMSIG(wstatus);
				shell->exit_code = 128 + g_signum;
			}
		}
		shell->nb_of_children--;
	}
	return (shell->exit_code);
}

void	visit_node(t_ast *node, t_io *io, t_shell *shell)
{
	if (node->type == SUBSHELL)
		visit_node(node->subsh.next, io, shell);
	if (node->type == COND)
		visit_cond(node->cond, io, shell);
	if (node->type == PIPE)
		visit_pipe(node->pipe, io, shell);
	if (node->type == CMD)
		visit_cmd(&(node->cmd), io, shell);
	if (node->type == REDIR)
		visit_redir(&(node->redir), io, shell);
	if (node->type == HEREDOC)
		visit_heredoc(node->heredoc, io, shell);
}

static void	reset_flags(t_shell *shell)
{
	shell->flags &= ~SYNTAX_PANIC;
	shell->flags &= ~HEREDOC_SIGINT;
	shell->flags &= ~EXEC_PANIC;
	shell->flags &= ~ENOENT_CMD;
	shell->flags &= ~EACCES_CMD;
	shell->flags &= ~ISDIR_CMD;
	shell->flags &= ~ENOENT_FILE;
	shell->flags &= ~EACCES_FILE;
	shell->flags &= ~HAS_PIPE;
	shell->flags &= ~MALLOC_FAILED;
}

static void	execute(t_ast *ast, t_shell *shell)
{
	t_io	io;

	io.input = STDIN_FILENO;
	io.output = STDOUT_FILENO;
	io.to_close = NO_FILE;
	io.prev_pipe_read = NO_FILE;
	visit_node(ast, &io, shell);
	shell->exit_code = wait_for_children(shell);
}

t_exit_code	executor(t_ast *ast, t_shell *shell)
{
	if (ast
		&& !(shell->flags & SYNTAX_PANIC)
		&& !(shell->flags & HEREDOC_SIGINT)
		&& !(shell->flags & MALLOC_FAILED))
		execute(ast, shell);
	free_ast(&(shell->ast_root));
	reset_flags(shell);
	restore_std_io(shell);
	return (shell->exit_code);
}
