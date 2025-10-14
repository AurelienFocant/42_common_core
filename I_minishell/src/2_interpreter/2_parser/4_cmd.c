/* ************************************************************************** */
/*                                                                            */
/*   4_cmd.c                                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:58:29 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:23:44 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "lexer.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char	**build_cmd_name(char *str, t_shell *shell)
{
	char	**name;

	name = malloc(sizeof(char *) * 2);
	if (!name)
		return (syntax_malloc_failed(shell));
	name[0] = ft_strdup(str);
	if (!name[0])
	{
		free(name);
		return (syntax_malloc_failed(shell));
	}
	name[1] = NULL;
	return (name);
}

static t_ast	*build_cmd_node(t_token **token, t_shell *shell)
{
	t_ast	*node;

	if (!is_tk_word(*token))
		return (NULL);
	node = malloc(sizeof(t_ast));
	if (!node)
		return (syntax_malloc_failed(shell));
	node->type = CMD;
	node->cmd.name = build_cmd_name((*token)->lexeme, shell);
	node->cmd.redir = NULL;
	advance(token);
	return (node);
}

t_ast	*parse_prefix(t_token **token, t_shell *shell)
{
	t_ast	*prefix;

	prefix = NULL;
	prefix = parse_redirect_list(token, &prefix, shell);
	return (prefix);
}

t_ast	*parse_suffix(t_token **token, t_cmd *cmd, t_ast **prefix, t_shell *sh)
{
	t_token		*previous;
	t_ast		*redir;

	previous = NULL;
	redir = NULL;
	while (true)
	{
		if (is_tk_redir(*token))
		{
			previous = advance(token);
			if (!is_tk_word(*token))
				return (syntax_panic(*prefix, sh));
			redir = build_redirection(token, previous, sh);
			if (!redir)
				return (free_node(*prefix));
			redir_add_front(redir, prefix);
		}
		else if (is_tk_word(*token))
			realloc_cmd_name(token, (*token)->lexeme, &(cmd->name), sh);
		else
			break ;
	}
	cmd->redir = *prefix;
	return (*prefix);
}

t_ast	*parse_command(t_token **token, t_shell *shell)
{
	t_ast	*prefix;
	t_ast	*node;

	prefix = NULL;
	node = NULL;
	prefix = parse_prefix(token, shell);
	node = build_cmd_node(token, shell);
	if (!node)
		return (prefix);
	parse_suffix(token, &(node->cmd), &prefix, shell);
	return (node);
}
