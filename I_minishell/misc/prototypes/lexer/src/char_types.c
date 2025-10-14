/* ************************************************************************** */
/*                                                                            */
/*   char_types.c                                         :::      ::::::::   */
/*   char_types.c                                       :+:      :+:    :+:   */
/*   By:  afocant  <afocant@student.s19.be>           +:+ +:+         +:+     */
/*   And: slangero <slangero@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:28:58 by afocant           #+#    #+#             */
/*   Updated: 2025/01/10 14:28:59 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_operator(char c)
{
	if (c == '(' || c == ')'
		|| c == '<' || c == '>'
		|| c == '|' || c == '&'
		|| c == ';')
		return (1);
	return (0);
}

int	is_metacharacter(char c)
{
	if (is_whitespace(c))
		return (1);
	if (is_operator(c))
		return (1);
	return (0);
}

int	is_whitespace(char c)
{
	if (c == '\0' || c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	is_eol(char *current)
{
	if (peek(current) == '\0')
		return (TRUE);
	return (FALSE);
}
