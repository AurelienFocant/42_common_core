/* ************************************************************************** */
/*                                                                            */
/*   interact_mode_signals.c                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:22:05 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:26:57 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

#include <signal.h>
#include <sys/ioctl.h>
#include <readline/readline.h>

extern int	g_signum;

static void	sigint_handler1(int signum)
{
	g_signum = signum;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	init_interactive_mode_signals(void)
{
	g_signum = 0;
	signal(SIGINT, sigint_handler1);
	signal(SIGQUIT, SIG_IGN);
	return ;
}
