/* ************************************************************************** */
/*                                                                            */
/*   2_double_op.c                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:51:11 by afocant           #+#    #+#             */
/*   Updated: 2025/03/19 19:57:24 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

bool	is_double_operator(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '&')
		return (true);
	return (false);
}

static t_token	*tk_single_op(char c)
{
	t_token	*token;

	token = NULL;
	if (c == '<')
		token = build_token(LESS, NULL);
	else if (c == '>')
		token = build_token(GREAT, NULL);
	else if (c == '|')
		token = build_token(OR, NULL);
	else if (c == '&')
		token = build_token(AMPERSAND, NULL);
	return (token);
}

static t_token	*tk_double_op(char c)
{
	t_token	*token;

	token = NULL;
	if (c == '<')
		token = build_token(D_LESS, NULL);
	else if (c == '>')
		token = build_token(D_GREAT, NULL);
	else if (c == '|')
		token = build_token(D_OR, NULL);
	else if (c == '&')
		token = build_token(D_AND, NULL);
	return (token);
}

t_token	*tokenise_double_operator(char **current)
{
	char	previous;
	t_token	*token;

	token = NULL;
	previous = advance_tk(current);
	if (previous != **current)
	{
		token = tk_single_op(previous);
	}
	else
	{
		token = tk_double_op(previous);
		advance_tk(current);
	}
	return (token);
}
