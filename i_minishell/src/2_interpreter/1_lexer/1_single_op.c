/* ************************************************************************** */
/*                                                                            */
/*   1_single_op.c                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:52:49 by afocant           #+#    #+#             */
/*   Updated: 2025/02/27 12:16:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"
#include "lexer.h"

#include <stdlib.h>
#include <stdbool.h>

bool	is_simple_operator(char c)
{
	if (c == '(' || c == ')' || c == ';')
		return (true);
	return (false);
}

t_token	*tokenise_simple_operator(char **current)
{
	t_token	*token;

	token = NULL;
	if (**current == '(')
		token = build_token(LEFT_PAREN, NULL);
	else if (**current == ')')
		token = build_token(RIGHT_PAREN, NULL);
	else if (**current == ';')
		token = build_token(SEMICOLON, NULL);
	advance_tk(current);
	return (token);
}
