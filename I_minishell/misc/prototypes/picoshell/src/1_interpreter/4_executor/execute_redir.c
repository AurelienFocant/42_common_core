#include "picoshell.h"

bool	duplicate_fd(t_ctxt *ctxt)
{
	dup2(ctxt->input, STDIN_FILENO);
	dup2(ctxt->output, STDOUT_FILENO);
	return (true);
}

bool	redirect_input(char *filename, t_ctxt *ctxt)
{
	int	fd;
	fd = open(filename, O_RDONLY);
	if (fd == NO_FILE)
		printf("prout file\n");
	if (ctxt->input != STDIN_FILENO)
		close(ctxt->input);
	ctxt->input = fd;
	return (true);
}

bool	redirect_output(char *filename, t_ctxt *ctxt)
{
	int	fd;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == NO_FILE)
		dprintf(STDERR_FILENO, "prout file\n");
	if (ctxt->output != STDOUT_FILENO)
		close(ctxt->output);
	ctxt->output = fd;
	return (true);
}

t_exit_code	execute_redir(t_redir redirnode, t_ctxt *ctxt, t_shell *shell)
{
	if (redirnode.type == IN)
		redirect_input(redirnode.filename, ctxt);
	else if (redirnode.type == OUT)
		redirect_output(redirnode.filename, ctxt);

	if (redirnode.next)
		execute_node(redirnode.next, ctxt, shell);
	return (EXIT_SUCCESS);
}
