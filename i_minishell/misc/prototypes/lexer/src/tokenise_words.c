/* ************************************************************************** */
/*                                                                            */
/*   tokenise_words.c                                     :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By:  afocant  <afocant@student.s19.be>           +:+ +:+         +:+     */
/*   And: slangero <slangero@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:30:08 by afocant           #+#    #+#             */
/*   Updated: 2025/01/10 15:43:00 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_word(char c)
{
	if (!is_metacharacter(c))
			return (1);
	return (0);
}

char	*extract_lexeme(char *start, char *end)
{
	char	*lexeme;
	int		len;
	int		i;

	len = end - start + 1;
	lexeme = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		lexeme[i] = *start;
		start++;
		i++;
	}
	lexeme[i] = '\0';
	return (lexeme);
}

t_token	*tokenise_word(char **current)
{
	t_token	*token;
	char	*start;
	char	*lexeme;

	start = *current;
	while (!is_eol(*current) && !is_metacharacter(peek(*current)))
		advance(current);
	lexeme = extract_lexeme(start, *current);
	token = build_token(WORD, lexeme);
	return (token);
}
