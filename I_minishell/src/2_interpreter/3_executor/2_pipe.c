/* ************************************************************************** */
/*                                                                            */
/*   2_pipe.c                                             :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:43:56 by afocant           #+#    #+#             */
/*   Updated: 2025/03/26 13:38:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

#include <unistd.h>

static t_io	setup_io(int input, int output, int to_close, int prev)
{
	t_io	new_io;

	new_io.input = input;
	new_io.output = output;
	new_io.to_close = to_close;
	new_io.prev_pipe_read = prev;
	return (new_io);
}

void	visit_pipe(t_pipe pipe_nd, t_io *io, t_shell *shell)
{
	int			pipefd[2];
	t_io		lh_io;
	t_io		rh_io;

	shell->flags |= HAS_PIPE;
	if (pipe(pipefd) == SYSCALL_ERROR)
	{
		write(2, "fork syscall error\n", 19);
		return ;
	}
	lh_io = setup_io(io->input, pipefd[1], pipefd[0], NO_FILE);
	rh_io = setup_io(pipefd[0], io->output, pipefd[1], io->prev_pipe_read);
	visit_node(pipe_nd.left, &lh_io, shell);
	close(pipefd[STDOUT_FILENO]);
	if (io->prev_pipe_read != NO_FILE)
		close(io->prev_pipe_read);
	visit_node(pipe_nd.right, &rh_io, shell);
	close(pipefd[STDIN_FILENO]);
}
