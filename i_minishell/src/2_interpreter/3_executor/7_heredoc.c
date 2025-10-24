/* ************************************************************************** */
/*                                                                            */
/*   6_heredoc.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:00:18 by afocant           #+#    #+#             */
/*   Updated: 2025/03/26 13:38:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

void	visit_heredoc(t_hdoc hdoc, t_io *io, t_shell *shell)
{
	if (hdoc.next)
		visit_node(hdoc.next, io, shell);
	if (io->input != STDIN_FILENO)
		close(io->input);
	io->input = hdoc.document;
}
