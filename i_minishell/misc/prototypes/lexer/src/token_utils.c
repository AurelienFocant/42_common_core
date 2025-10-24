/* ************************************************************************** */
/*                                                                            */
/*   token_utils.c                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By:  afocant  <afocant@student.s19.be>           +:+ +:+         +:+     */
/*   And: slangero <slangero@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:25:57 by afocant           #+#    #+#             */
/*   Updated: 2025/01/10 15:40:25 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	peek(char *current)
{
	return (*(current + 1));
}

int	advance(char **current)
{
	if (peek(*current) == '\0')
		return (FALSE);
	(*current)++;
	return (TRUE);
}

void	print_token_class(t_token *token)
{
	if (token->class == WORD)
		printf("token class is: %s	lexeme is: %s\n", "WORD", token->lexeme);
	if (token->class == PIPE)
		printf("token class is: %s\n", "PIPE");
	if (token->class == GREAT)
		printf("token class is: %s\n", "GREAT");
	if (token->class == LESS)
		printf("token class is: %s\n", "LESS");
	if (token->class == DGREAT)
		printf("token class is: %s\n", "DGREAT");
	if (token->class == DLESS)
		printf("token class is: %s\n", "DLESS");
	if (token->class == LEFT_PAREN)
		printf("token class is: %s\n", "LEFT_PAREN");
	if (token->class == RIGHT_PAREN)
		printf("token class is: %s\n", "RIGHT_PAREN");
	if (token->class == LOG_AND)
		printf("token class is: %s\n", "LOG_AND");
	if (token->class == LOG_OR)
		printf("token class is: %s\n", "LOG_OR");
	if (token->class == AMPERSAND)
		printf("token class is: %s\n", "AMPERSAND");
	if (token->class == SEMICOLON)
		printf("token class is: %s\n", "SEMICOLON");
}
