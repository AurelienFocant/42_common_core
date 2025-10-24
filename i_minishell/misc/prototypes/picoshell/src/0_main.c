/* ************************************************************************** */
/*                                                                            */
/*   main.c                                               :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By:  afocant  <afocant@student.s19.be>           +:+ +:+         +:+     */
/*   And: slangero <slangero@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:32:45 by afocant           #+#    #+#             */
/*   Updated: 2025/02/09 16:54:10 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "picoshell.h"
#include "readline/readline.h"
#include <signal.h>
#include <sys/ioctl.h>

int	g_signum = 0;

char	*expand(char *var, t_shell *shell)
{
	char	**envp;

	envp = shell->envp;
	while (*envp)
	{
		if (ft_strncmp(*envp, var, ft_strlen(var)) == EXIT_SUCCESS)
			return (ft_strdup(*(envp) + ft_strlen(var)));
		envp++;
	}
	return (NULL);
}

t_exit_code	print_error(char *msg)
{
	ft_dprintf(STDERR_FILENO, "hello you %s\n", msg);
	exit(EXIT_FAILURE);
}

void	sigint_handler(int signum)
{
	(void) signum;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_redisplay();
	rl_on_new_line();
}

void	init_signals(void)
{
	struct sigaction	saction;

	saction.sa_handler = sigint_handler;
	(void) saction;
	sigaction(SIGINT, &saction, NULL);
}

void	init_shell(char **envp, t_shell *shell)
{
	shell->envp = envp;
	shell->flags = 0;
	shell->current_exit_code = EXIT_SUCCESS;
	shell->last_exit_code = EXIT_SUCCESS;
	read_history_file(shell);
	init_signals();
}

int	main(int argc, char **argv, char **envp)
{
	t_shell			shell;

	init_shell(envp, &shell);
	if (argc == 2)
	{
		shell.current_exit_code = script_mode(argv[1], &shell);
	}
	else if (argc > 1)
	{
		if (ft_strcmp(argv[1], "-c") == EXIT_SUCCESS)
			shell.current_exit_code = command_mode(argv[2], &shell);
		else
			print_error("wrong option");
	}
	else
	{
		shell.current_exit_code = interactive_mode(&shell);
	}
	return (shell.current_exit_code);
}
