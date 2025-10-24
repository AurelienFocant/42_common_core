/* ************************************************************************** */
/*                                                                            */
/*   0_parser.c                                           :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:35:58 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:23:31 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

#include <stdlib.h>

t_ast	*parse_command_line(t_token **tokens, t_shell *shell)
{
	shell->ast_root = parse_conditional_line(tokens, shell);
	return (shell->ast_root);
}

t_ast	*parser(t_token *tokens, t_shell *shell)
{
	shell->ast_root = parse_command_line(&tokens, shell);
	if (tokens->type != EOL && !(shell->flags & MALLOC_FAILED))
		shell->flags |= SYNTAX_PANIC;
	if (shell->flags & SYNTAX_PANIC)
		print_and_panic(tokens, shell->ast_root, shell);
	if (shell->flags & SYNTAX_PANIC && (!(shell->flags & INTERACT_MODE)))
		free_and_exit_shell(NULL, shell->exit_code, shell);
	if (shell->flags & DEBUG_FLAG || shell->flags & GRAPH_FLAG)
		visualizer(shell->ast_root);
	free_tokens(&(shell->token_stream));
	return (shell->ast_root);
}
