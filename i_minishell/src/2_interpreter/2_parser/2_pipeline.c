/* ************************************************************************** */
/*                                                                            */
/*   2_pipeline.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:48:53 by afocant           #+#    #+#             */
/*   Updated: 2025/03/25 21:39:06 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"
#include "lexer.h"
#include "parser.h"

#include <stdbool.h>
#include <stdlib.h>

static t_ast	*build_pipe_node(t_ast *left, t_ast *right, t_shell *shell)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
	{
		free_ast(&left);
		free_ast(&right);
		return (syntax_malloc_failed(shell));
	}
	node->type = PIPE;
	node->pipe.left = left;
	node->pipe.right = right;
	return (node);
}

t_ast	*parse_pipeline(t_token **token, t_shell *shell)
{
	t_ast	*node;
	t_ast	*other_node;

	node = NULL;
	other_node = NULL;
	node = parse_subshell(token, shell);
	if (!node)
		return (NULL);
	if (is_tk_pipe(*token) && !(shell->flags & SYNTAX_PANIC))
	{
		advance(token);
		if ((*token)->type == EOL)
			return (syntax_panic(node, shell));
		other_node = parse_pipeline(token, shell);
		if (!other_node)
			return (free_ast(&node));
		node = build_pipe_node(node, other_node, shell);
	}
	return (node);
}
