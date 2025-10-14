/* ************************************************************************** */
/*                                                                            */
/*   3_subshell.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:51:27 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:23:40 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "parser.h"

#include <stdlib.h>

static t_ast	*build_subshell_node(t_shell *shell)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (syntax_malloc_failed(shell));
	node->type = SUBSHELL;
	node->subsh.next = NULL;
	return (node);
}

static t_ast	*traverse_tree(t_ast *node)
{
	if (node->type == SUBSHELL)
		return (traverse_tree(node->subsh.next));
	if (node->type == COND)
		return (traverse_tree(node->cond.left));
	if (node->type == PIPE)
		return (traverse_tree(node->pipe.left));
	if (node->type == CMD)
	{
		if (node->cmd.redir)
			return (traverse_tree(node->cmd.redir));
		else
			return (node);
	}
	if (node->type == REDIR)
	{
		if (node->redir.next)
			return (traverse_tree(node->redir.next));
		else
			return (node);
	}
	return (NULL);
}

static t_ast	*add_redir_to_subsh(t_ast *subsh, t_token **token, t_shell *sh)
{
	t_ast	*redir_lst;
	t_ast	*first_redir;

	redir_lst = NULL;
	redir_lst = parse_redirect_list(token, &redir_lst, sh);
	if (!redir_lst)
		return (NULL);
	first_redir = traverse_tree(subsh);
	if (first_redir->type == CMD)
		first_redir->cmd.redir = redir_lst;
	else
		first_redir->redir.next = redir_lst;
	return (redir_lst);
}

t_ast	*parse_subshell(t_token **token, t_shell *shell)
{
	t_ast	*node;

	node = NULL;
	if (match(LEFT_PAREN, token))
	{
		advance(token);
		node = build_subshell_node(shell);
		if (!node)
			return (syntax_malloc_failed(shell));
		node->subsh.next = parse_command_line(token, shell);
		if (!match(RIGHT_PAREN, token))
			return (syntax_panic(node, shell));
		if (!node->subsh.next)
			return (free_ast(&node));
		advance(token);
		add_redir_to_subsh(node->subsh.next, token, shell);
	}
	else
		node = parse_command(token, shell);
	return (node);
}
