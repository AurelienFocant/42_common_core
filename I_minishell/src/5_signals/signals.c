/* ************************************************************************** */
/*                                                                            */
/*   signals.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:06:37 by afocant           #+#    #+#             */
/*   Updated: 2025/03/20 11:54:01 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termios.h>

extern int	g_signum;

static void	sigquit_handler2(int signum)
{
	g_signum = signum;
	write(STDERR_FILENO, "Quit: 3\n", 8);
}

static void	sigint_handler2(int signum)
{
	g_signum = signum;
	write(STDERR_FILENO, "\n", 1);
}

void	sigint_hdoc_handler(int signum)
{
	struct termios	term;

	g_signum = signum;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	term.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	set_signals_waiting_parent(void)
{
	signal(SIGINT, sigint_handler2);
	signal(SIGQUIT, sigquit_handler2);
}

void	reset_signals_default(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	return ;
}
