/* ************************************************************************** */
/*                                                                            */
/*   9_utils.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:24:20 by afocant           #+#    #+#             */
/*   Updated: 2025/03/19 20:02:59 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

void	skip_whitespace(char **str)
{
	while (**str && ft_isspace(**str))
		(*str)++;
}

char	advance_tk(char **current)
{
	char	previous;

	if (!**current)
		return ('\0');
	previous = **current;
	(*current)++;
	return (previous);
}

t_token	*build_token(t_tk_type type, char *lexeme)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->lexeme = lexeme;
	token->next = NULL;
	return (token);
}

static t_token	*tk_list_last_tk(t_token *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	add_back_tk(t_token *new, t_token **list)
{
	if (!new || !list)
		return ;
	if (*list)
		tk_list_last_tk(*list)->next = new;
	else
		*list = new;
}
