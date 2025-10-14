/* ************************************************************************** */
/*                                                                            */
/*   1_cond.c                                             :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:01:49 by afocant           #+#    #+#             */
/*   Updated: 2025/03/26 13:38:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

#include <stdlib.h>

void	visit_cond(t_cond cond, t_io *io, t_shell *shell)
{
	t_exit_code	exit_code;

	visit_node(cond.left, io, shell);
	exit_code = wait_for_children(shell);
	if (cond.type == AND_IF && exit_code == EXIT_SUCCESS)
		visit_node(cond.right, io, shell);
	if (cond.type == OR_IF && exit_code != EXIT_SUCCESS)
		visit_node(cond.right, io, shell);
}
