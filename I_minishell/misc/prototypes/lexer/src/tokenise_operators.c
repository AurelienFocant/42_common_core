/* ************************************************************************** */
/*                                                                            */
/*   tokenise_operators.c                                 :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By:  afocant  <afocant@student.s19.be>           +:+ +:+         +:+     */
/*   And: slangero <slangero@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:26 by afocant           #+#    #+#             */
/*   Updated: 2025/01/10 15:35:24 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_single_operator(char c)
{
	if (c == '(' || c == ')' || c == ';')
		return (1);
	return (0);
}

t_token	*tokenise_single_operator(char **current)
{
	t_token	*token;

	token = NULL;
	if (**current == '(')
		token = build_token(LEFT_PAREN, NULL);
	else if (**current == ')')
		token = build_token(RIGHT_PAREN, NULL);
	else if (**current == ';')
		token = build_token(SEMICOLON, NULL);
	return (token);
}

int	is_double_operator(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '&')
		return (1);
	return (0);
}

t_token *tokenise_double_operator(char **current)
{
	t_token	*token;

	token = NULL;
	if (peek(*current) != **current)
	{
		if (**current == '<')
			token = build_token(LESS, NULL);
		else if (**current == '>')
			token = build_token(GREAT, NULL);
		else if (**current == '|')
			token = build_token(PIPE, NULL);
		else if (**current == '&')
			token = build_token(AMPERSAND, NULL);
	}
	else
	{
		if (**current == '<')
			token = build_token(DLESS, NULL);
		else if (**current == '>')
			token = build_token(DGREAT, NULL);
		else if (**current == '|')
			token = build_token(LOG_OR, NULL);
		else if (**current == '&')
			token = build_token(LOG_AND, NULL);
		advance(current);
	}
	return (token);
}
