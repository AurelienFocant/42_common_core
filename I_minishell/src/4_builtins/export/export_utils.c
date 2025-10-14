/* ************************************************************************** */
/*                                                                            */
/*   export_utils.c                                       :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:05:43 by afocant           #+#    #+#             */
/*   Updated: 2025/03/31 22:27:10 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "tinyshell.h"

bool	is_identifier(char *word, int *j, bool *error)
{
	bool	ident;
	size_t	i;

	ident = true;
	if (!ft_isalpha(word[0]))
		if (word[0] != '_')
			ident = false;
	i = 0;
	while (word[i] && word[i] != '=' && ident)
	{
		if (!(ft_isalnum(word[i]) || word[i] == '_'))
			if (!(word[i] == '+' && word[i + 1] == '='))
				ident = false;
		i++;
	}
	if (!ident)
	{
		ft_dprintf(STDERR_FILENO,
			"tiny: export: `%s': not a valid identifier\n", word);
		(*j)++;
		*error = true;
		return (false);
	}
	return (true);
}

char	*has_assignment(char *word, int *i)
{
	char	*assign;

	assign = ft_strchr(word, '=');
	if (!assign)
	{
		ft_dprintf(STDERR_FILENO,
			"tiny: export: %s: assignment has to happen during export\n",
			word);
		(*i)++;
		return (NULL);
	}
	return (assign);
}
