/* ************************************************************************** */
/*                                                                            */
/*   7_heredoc.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:13:07 by afocant           #+#    #+#             */
/*   Updated: 2025/03/28 19:23:25 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "lexer.h"
#include "parser.h"

#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>

extern int	g_signum;

static int	hdoc_count_wo_quotes(char *str, char quote)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str != quote)
			i++;
		str++;
	}
	return (i);
}

static char	*hdoc_remove_quotes(char **str, char quote, t_shell *shell)
{
	int		count;
	char	*res;
	char	*s;
	int		i;

	count = hdoc_count_wo_quotes(*str, quote);
	res = malloc(count + 1);
	if (!res)
		return (syntax_malloc_failed(shell));
	s = *str;
	i = 0;
	while (*s)
	{
		if (*s != quote)
			res[i++] = *s;
		s++;
	}
	res[i] = '\0';
	free(*str);
	*str = res;
	return (res);
}

static int	parse_hdoc_lines(char **delim, char quote, int *pipev, t_shell *sh)
{
	char	*line;

	line = readline("> ");
	if (!line)
		return (hdoc_unexp_eof(*delim));
	while (line && (ft_strcmp(line, *delim) != EXIT_SUCCESS))
	{
		if (g_signum == SIGINT)
			return (hdoc_interrupted(pipev, line, sh));
		if (!quote)
			parameter_expansion(&line, sh);
		ft_dprintf(pipev[STDOUT_FILENO], "%s\n", line);
		free(line);
		line = readline("> ");
		if (!line)
			return (hdoc_unexp_eof(*delim));
	}
	return (EXIT_SUCCESS);
}

static int	parse_heredoc(char **delim, t_shell *shell)
{
	int		pipev[2];
	char	quote;
	int		hdoc;

	signal(SIGINT, sigint_hdoc_handler);
	if (pipe(pipev) == SYSCALL_ERROR)
		return (hdoc_pipe_error(shell));
	quote = has_quote(*delim);
	if (quote)
		hdoc_remove_quotes(delim, quote, shell);
	hdoc = parse_hdoc_lines(delim, quote, pipev, shell);
	if (hdoc == NO_FILE)
		return (NO_FILE);
	close(pipev[STDOUT_FILENO]);
	return (pipev[STDIN_FILENO]);
}

t_ast	*build_heredoc_node(t_token **token, t_shell *shell)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (syntax_malloc_failed(shell));
	node->type = HEREDOC;
	node->heredoc.delim = ft_strdup((*token)->lexeme);
	if (!node->heredoc.delim)
	{
		free(node);
		return (syntax_malloc_failed(shell));
	}
	node->heredoc.document = parse_heredoc(&(node->heredoc.delim), shell);
	node->heredoc.next = NULL;
	advance(token);
	if (node->heredoc.document == NO_FILE)
	{
		free(node->heredoc.delim);
		free(node);
		return (NULL);
	}
	return (node);
}
