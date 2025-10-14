/* ************************************************************************** */
/*                                                                            */
/*   6_redir.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:26:12 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:23:46 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "lexer.h"
#include "parser.h"

#include <stdlib.h>
#include <stdbool.h>

static t_redir_type	get_redir_type(t_token *token)
{
	if (token->type == LESS)
		return (IN);
	if (token->type == GREAT)
		return (OUT);
	if (token->type == D_GREAT)
		return (APPEND);
	return (-1);
}

static t_ast	*build_redir_node(t_token **tk, t_token *prev, t_shell *shell)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (syntax_malloc_failed(shell));
	node->type = REDIR;
	node->redir.type = get_redir_type(prev);
	node->redir.filename = ft_strdup((*tk)->lexeme);
	if (!node->redir.filename)
	{
		free(node);
		return (syntax_malloc_failed(shell));
	}
	node->redir.next = NULL;
	advance(tk);
	return (node);
}

void	redir_add_front(t_ast *new, t_ast **prefix)
{
	new->redir.next = *prefix;
	*prefix = new;
}

t_ast	*build_redirection(t_token **token, t_token *previous, t_shell *shell)
{
	t_ast	*redir;

	if (previous->type == D_LESS)
		redir = build_heredoc_node(token, shell);
	else
		redir = build_redir_node(token, previous, shell);
	return (redir);
}

t_ast	*parse_redirect_list(t_token **token, t_ast **redir_lst, t_shell *shell)
{
	t_token	*previous;
	t_ast	*redir;

	redir = NULL;
	while (is_tk_redir(*token))
	{
		previous = advance(token);
		if (!is_tk_word(*token))
			return (syntax_panic(*redir_lst, shell));
		redir = build_redirection(token, previous, shell);
		if (!redir)
			break ;
		redir_add_front(redir, redir_lst);
	}
	return (*redir_lst);
}
