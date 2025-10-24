/* ************************************************************************** */
/*                                                                            */
/*   8_utils.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:15:35 by afocant           #+#    #+#             */
/*   Updated: 2025/03/26 13:38:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

void	restore_std_io(t_shell *shell)
{
	dup2(shell->std_in, STDIN_FILENO);
	dup2(shell->std_out, STDOUT_FILENO);
}

void	duplicate_fds(t_io *io)
{
	if (io->input != STDIN_FILENO && io->input != NO_FILE)
	{
		dup2(io->input, STDIN_FILENO);
		close(io->input);
	}
	if (io->output != STDOUT_FILENO && io->output != NO_FILE)
	{
		dup2(io->output, STDOUT_FILENO);
		close(io->output);
	}
	if (io->to_close != NO_FILE)
		close(io->to_close);
}
