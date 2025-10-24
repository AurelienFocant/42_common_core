/* ************************************************************************** */
/*                                                                            */
/*   interpreter.c                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:15:58 by afocant           #+#    #+#             */
/*   Updated: 2025/03/24 12:37:14 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <readline/readline.h>

extern int	g_signum;

static void	check_scriptfile(char *file)
{
	if (access(file, F_OK) != EXIT_SUCCESS)
	{
		ft_dprintf(STDERR_FILENO,
			"tiny: %s: no such file or directory\n", file);
		exit(ENOENT_ERROR);
	}
	else if (access(file, R_OK) != EXIT_SUCCESS)
	{
		ft_dprintf(STDERR_FILENO,
			"tiny: %s: permission denied\n", file);
		exit(EACCES_ERROR);
	}
}

void	script_mode(char *file, t_shell *shell)
{
	int		fd;

	check_scriptfile(file);
	fd = open(file, O_RDONLY);
	if (fd == NO_FILE)
	{
		ft_dprintf(STDERR_FILENO, "error opening script file\n");
		exit(EXIT_FAILURE);
	}
	shell->input = ft_get_next_line(fd);
	while (shell->input)
	{
		command_line_interpreter(shell->input, shell);
		ft_free_null((void **) &shell->input);
		shell->input = ft_get_next_line(fd);
		shell->line_nb++;
	}
	free_shell(shell);
	close(fd);
	return ;
}

void	command_mode(char *line, t_shell *shell)
{
	if (line)
		command_line_interpreter(line, shell);
	free_shell(shell);
	exit(shell->exit_code);
}

void	interactive_mode(t_shell *shell)
{
	read_histfile(shell);
	while (true)
	{
		init_interactive_mode_signals();
		g_signum = 0;
		shell->input = readline("tinyshell $ ");
		if (g_signum == SIGINT)
		{
			shell->exit_code = 128 + SIGINT;
			g_signum = 0;
		}
		if (!shell->input)
			free_and_exit_shell(NULL, shell->exit_code, shell);
		if (*(shell->input))
		{
			command_line_interpreter(shell->input, shell);
			populate_histfile(shell->input, shell->histfile);
			free(shell->input);
		}
	}
}

t_exit_code	command_line_interpreter(char *line, t_shell *shell)
{
	shell->token_stream = lexer(line, shell);
	shell->ast_root = parser(shell->token_stream, shell);
	shell->exit_code = executor(shell->ast_root, shell);
	return (shell->exit_code);
}
