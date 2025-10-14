/* ************************************************************************** */
/*                                                                            */
/*   0_main.c                                             :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:51:07 by afocant           #+#    #+#             */
/*   Updated: 2025/03/19 18:29:00 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

#include <stdbool.h>
#include <stdint.h>

int	g_signum;

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	init_shell(envp, &shell);
	parse_args(argc, argv, &shell);
	if (shell.flags & INTERACT_MODE)
		interactive_mode(&shell);
	else if (shell.flags & COMMAND_MODE)
		command_mode(shell.input, &shell);
	else if (shell.flags & SCRIPT_MODE)
		script_mode(shell.script_file, &shell);
}
