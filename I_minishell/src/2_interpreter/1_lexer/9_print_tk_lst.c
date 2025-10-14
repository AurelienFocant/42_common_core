/* ************************************************************************** */
/*                                                                            */
/*   9_debug.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:57:05 by afocant           #+#    #+#             */
/*   Updated: 2025/03/19 19:56:12 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>

static char	*tk_type_str(t_tk_type type)
{
	if (type == SEMICOLON)
		return ("SEMICOLON");
	else if (type == LEFT_PAREN)
		return ("LEFT_PAREN");
	else if (type == RIGHT_PAREN)
		return ("RIGHT_PAREN");
	else if (type == GREAT)
		return ("GREAT");
	else if (type == LESS)
		return ("LESS");
	else if (type == D_GREAT)
		return ("D_GREAT");
	else if (type == D_LESS)
		return ("D_LESS");
	else if (type == AMPERSAND)
		return ("AMPERSAND");
	else if (type == OR)
		return ("OR");
	else if (type == D_AND)
		return ("D_AND");
	else if (type == D_OR)
		return ("D_OR");
	else if (type == WORD)
		return ("WORD");
	return ("EOL");
}

void	print_tk_stream(t_token *list)
{
	if (!list)
		return ;
	while (list)
	{
		ft_dprintf(STDERR_FILENO, "tk_type is %s", tk_type_str(list->type));
		if (list->type == WORD)
			ft_dprintf(STDERR_FILENO, " lexeme is %s", list->lexeme);
		ft_dprintf(STDERR_FILENO, "\n");
		list = list->next;
	}
}
