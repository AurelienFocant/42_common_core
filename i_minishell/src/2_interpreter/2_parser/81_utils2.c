/* ************************************************************************** */
/*                                                                            */
/*   81_utils2.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:26:26 by afocant           #+#    #+#             */
/*   Updated: 2025/03/12 15:28:16 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include <stdbool.h>

bool	is_tk_word(t_token *token)
{
	if (token->type == WORD)
		return (true);
	return (false);
}

bool	is_tk_redir(t_token *token)
{
	if (token->type == LESS
		|| token->type == D_LESS
		|| token->type == GREAT
		|| token->type == D_GREAT)
		return (true);
	else
		return (false);
}

bool	is_tk_cond(t_token *token)
{
	if (token->type == D_AND || token->type == D_OR)
		return (true);
	return (false);
}

bool	is_tk_pipe(t_token *token)
{
	if (token->type == OR)
		return (true);
	return (false);
}
