#include "picoshell.h"
#include "parser.h"
#include "lexer.h"
#include <signal.h>

extern int g_signum;

bool	is_redir_tk(t_token **token)
{
	if (!(*token))
		return (false);
	if ((*token)->class == LESS)
		return (true);
	if ((*token)->class == GREAT)
		return (true);
	if ((*token)->class == DLESS)
		return (true);
	if ((*token)->class == DGREAT)
		return (true);
	return (false);
}

t_redir_type	redir_type(t_token **token)
{
	t_redir_type	type;
	
	type = -1;
	if ((*token)->class == LESS)
		type = IN;
	else if ((*token)->class == GREAT)
		type = OUT;
	else if ((*token)->class == DLESS)
		type = HEREDOC;
	else if ((*token)->class == DGREAT)
		type = APPEND;
	return (type);
}

t_node	*get_last(t_node *redir)
{
	while (redir->data.redir.next)
		redir = redir->data.redir.next;
	return (redir);
}

bool	redir_add_back(t_node **node, t_node *new_node)
{
	if (!node || !new_node)
		return (false);
	if (!*node)
		*node = new_node;
	else
		get_last(*node)->data.redir.next = new_node;
	return (true);
}

char	*create_rdm_file(char *str, t_token **token)
{
	int	n;
	char *res;
	char *tmp;

	n = ((unsigned long) *token & 0xFFFFFFF);
	tmp = ft_itoa(n);
	res = ft_strjoin(str, tmp);
	return (res);
}

void	heredoc_handler(int signum)
{
	g_signum = signum;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_redisplay();
	rl_on_new_line();
}

void	init_heredoc_signal(void)
{
	struct sigaction	saction;

	saction.sa_handler = heredoc_handler;
	(void) saction;
	sigaction(SIGINT, &saction, NULL);
	// rl_replace_line("", 0);
	rl_redisplay();
	rl_on_new_line();
}

void	write_heredoc_file(int fd, char *delim)
{
	char *line;

	init_heredoc_signal();
	line = readline("heredoc >> ");
	while (line && ft_strcmp(line, delim) != EXIT_SUCCESS)
	{
		if (g_signum)
		{
			return ;
		}
		ft_dprintf(fd, "%s\n", line);
		line = readline("heredoc >> ");
	}
}

char	*parse_heredoc(t_token **token)
{
	char	*filename;
	int		fd;

	filename = create_rdm_file("/tmp/.heredoc", token);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	write_heredoc_file(fd, (*token)->lexeme);
	close(fd);
	return (filename);
}

t_node	*build_redir_node(t_token **token)
{
	t_node	*new_redir;

	new_redir = ft_calloc(1, sizeof(t_node));
	//protec malloc
	new_redir->type = REDIR;
	new_redir->data.redir.type = redir_type(token);
	consume(token);
	if (new_redir->data.redir.type == HEREDOC)
		new_redir->data.redir.filename = parse_heredoc(token);
	else
		new_redir->data.redir.filename = parse_word(token);
	consume(token);
	new_redir->data.redir.next = NULL;
	return (new_redir);
}
