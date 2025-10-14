/* ************************************************************************** */
/*                                                                            */
/*   3_words.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:57:52 by afocant           #+#    #+#             */
/*   Updated: 2025/03/27 18:58:02 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

size_t	get_word_len(char *start, char *current)
{
	size_t	len;

	len = 0;
	while (start < current)
	{
		len++;
		start++;
	}
	return (len);
}

static char	*extract_lexeme(char *start, char *current)
{
	size_t	len;
	char	*lexeme;
	size_t	i;

	len = get_word_len(start, current);
	lexeme = malloc(sizeof(char) * (len + 1));
	if (!lexeme)
		return (NULL);
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

static bool	go_to_closing_quote(char quote, char **current)
{
	advance_tk(current);
	while (**current)
	{
		if (**current == quote && (*(*current) - 1) != '\\')
			return (true);
		advance_tk(current);
	}
	ft_dprintf(STDERR_FILENO, "Quotes have not been closed\n");
	return (false);
}

static char	**go_to_end_of_word(char **current)
{
	while (**current && !is_metacharacter(**current))
	{
		if (is_quote(**current))
		{
			if (!go_to_closing_quote(**current, current))
				return (NULL);
		}
		advance_tk(current);
	}
	return (current);
}

t_token	*tokenise_word(char **current)
{
	char	*start;
	char	*lexeme;
	t_token	*token;

	start = *current;
	if (!go_to_end_of_word(current))
		return (NULL);
	lexeme = extract_lexeme(start, *current);
	if (!lexeme)
		return (NULL);
	token = build_token(WORD, lexeme);
	return (token);
}
