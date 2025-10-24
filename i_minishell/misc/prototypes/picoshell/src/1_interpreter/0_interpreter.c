#include "picoshell.h"

t_exit_code	command_mode(char *line, t_shell *shell)
{
	t_exit_code	exit_code;

	exit_code = command_line_interpreter(line, shell);
	return (exit_code);
}

t_exit_code	script_mode(char *filename, t_shell *shell)
{
	(void) shell;
	(void) filename;
	return (EXIT_SUCCESS);
}

t_exit_code	interactive_mode(t_shell *shell)
{
	t_exit_code	exit_code;
	char		*line;

	while (true)
	{
		line = readline("pico > ");
		if (!line)
			return (EXIT_FAILURE);
		if (*line)
		{
			populate_history(line, shell);
			exit_code = command_line_interpreter(line, shell);
		}
		free(line);
	}
	return (exit_code);
}

t_exit_code	command_line_interpreter(char *line, t_shell *shell)
{
	t_token		*tokens;
	t_node		*ast;

	tokens = lexer(line);
	ast = parser(&tokens);
	shell->flags |= DEBUG_FLAG;
	if (shell->flags & DEBUG_FLAG)
		visualizer(ast);
	shell->current_exit_code = executer(ast, shell);
	shell->last_exit_code = shell->current_exit_code;
	return (shell->current_exit_code);
}
