/* ************************************************************************** */
/*                                                                            */
/*   8_utils.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:27:54 by afocant           #+#    #+#             */
/*   Updated: 2025/02/11 15:08:43 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include <stdbool.h>

t_token	*advance(t_token **token)
{
	t_token	*previous;

	previous = (*token);
	if ((*token)->next)
		(*token) = (*token)->next;
	return (previous);
}

bool	match(t_tk_type tk_type, t_token **token)
{
	if ((*token)->type == tk_type)
		return (true);
	return (false);
}
