/* ************************************************************************** */
/*                                                                            */
/*   4_words_utils.c                                      :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:01:57 by afocant           #+#    #+#             */
/*   Updated: 2025/02/27 12:21:37 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdbool.h>

bool	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

bool	is_metacharacter(char c)
{
	if (ft_isspace(c))
		return (true);
	if (ft_strchr("|&;()<>", c))
		return (true);
	return (false);
}

bool	is_word_char(char c)
{
	if (!is_metacharacter(c))
		return (true);
	return (false);
}
