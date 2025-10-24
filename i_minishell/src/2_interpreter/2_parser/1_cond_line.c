/* ************************************************************************** */
/*                                                                            */
/*   1_cmd_line.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:13:46 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:23:34 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"
#include "parser.h"
#include "tinyshell.h"

#include <stdbool.h>
#include <stdlib.h>

static t_cond_type	get_cond_type(t_tk_type tk_type)
{
	if (tk_type == D_AND)
		return (AND_IF);
	return (OR_IF);
}

static t_ast	*build_cond_node(
	t_ast *left, t_ast *right,
	t_tk_type tk_type, t_shell *shell)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
	{
		free_ast(&left);
		free_ast(&right);
		return (syntax_malloc_failed(shell));
	}
	node->type = COND;
	node->cond.type = get_cond_type(tk_type);
	node->cond.left = left;
	node->cond.right = right;
	return (node);
}

t_ast	*parse_conditional_line(t_token **token, t_shell *shell)
{
	t_ast	*node;
	t_token	*cond;
	t_ast	*other_node;

	node = NULL;
	other_node = NULL;
	node = parse_pipeline(token, shell);
	if (!node)
		return (NULL);
	while (is_tk_cond(*token) && !(shell->flags & SYNTAX_PANIC))
	{
		cond = advance(token);
		if ((*token)->type == EOL)
			return (syntax_panic(node, shell));
		other_node = parse_pipeline(token, shell);
		if (!other_node)
			return (free_ast(&node));
		node = build_cond_node(node, other_node, cond->type, shell);
	}
	return (node);
}
