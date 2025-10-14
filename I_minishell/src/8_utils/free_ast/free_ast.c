/* ************************************************************************** */
/*                                                                            */
/*   free_ast.c                                           :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:16:07 by afocant           #+#    #+#             */
/*   Updated: 2025/02/27 16:44:47 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"
#include "parser.h"

#include <stdlib.h>

void	*free_node(t_ast *node)
{
	if (!node)
		return (NULL);
	if (node->type == SUBSHELL)
		free_node(node->subsh.next);
	else if (node->type == COND)
		free_cond(node->cond);
	else if (node->type == PIPE)
		free_pipe(node->pipe);
	else if (node->type == CMD)
		free_cmd(node->cmd);
	else if (node->type == REDIR)
		free_redir(node->redir);
	else if (node->type == HEREDOC)
		free_heredoc(node->heredoc);
	free(node);
	return (NULL);
}

t_ast	*free_ast(t_ast **ast_root)
{
	t_ast	*ast;

	ast = *ast_root;
	if (ast)
		free_node(ast);
	*ast_root = NULL;
	return (NULL);
}
