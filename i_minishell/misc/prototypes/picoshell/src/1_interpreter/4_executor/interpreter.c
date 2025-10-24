#include "picoshell.h"
#include "parser.h"
#include "prototypes_picoshell.h"
#include "interpreter.h"

t_exit_code	execute_node(t_node	*node, t_ctxt *ctxt, t_shell *shell)
{
	t_exit_code	exit_code;

	exit_code = EXIT_FAILURE;
	if (node->type == PIPE)
		exit_code = execute_pipe(node->data.pipe, ctxt, shell);
	else if (node->type == CMD)
		exit_code = execute_cmd(node->data.cmd, ctxt, shell);
	else if (node->type == REDIR)
		exit_code = execute_redir(node->data.redir, ctxt, shell);
	return (exit_code);
}

t_exit_code	execute_pipe(t_pipe	pipenode, t_ctxt *ctxt, t_shell *shell)
{
	int	pipefd[2];
	t_exit_code	exit_code;
	t_ctxt	left_ctxt;
	t_ctxt	right_ctxt;

	pipe(pipefd);
	// error mngmt !

	left_ctxt.input = ctxt->input;
	left_ctxt.output = pipefd[STDOUT_FILENO];
	left_ctxt.to_close = pipefd[STDIN_FILENO];
	execute_node(pipenode.left, &left_ctxt, shell);
	close(pipefd[STDOUT_FILENO]);

	right_ctxt.input = pipefd[STDIN_FILENO]; 
	right_ctxt.output = ctxt->output;
	exit_code = execute_node(pipenode.right, &right_ctxt, shell);
	close(pipefd[STDIN_FILENO]);

	return (exit_code);
}

t_exit_code	executer(t_node *ast, t_shell *shell)
{
	t_exit_code	exit_code;
	t_ctxt		ctxt;

	ctxt.input = STDIN_FILENO;
	ctxt.output = STDOUT_FILENO;
	ctxt.to_close = NO_FILE;
	exit_code = execute_node(ast, &ctxt, shell);
	return (exit_code);
}
