/* ************************************************************************** */
/*                                                                            */
/*   expand.c                                             :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:11:33 by afocant           #+#    #+#             */
/*   Updated: 2025/03/31 18:43:00 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "expander.h"

#include <stdlib.h>
#include <stdbool.h>

static bool	dquote_has_exp(char **str)
{
	(*str)++;
	while (**str && **str != '"')
	{
		if (**str == '$')
			return (true);
		(*str)++;
	}
	return (false);
}

static bool	squote_has_exp(char **str)
{
	while (**str && **str != '\'')
		(*str)++;
	return (true);
}

bool	has_expansion(char *str)
{
	while (*str)
	{
		if (*str == '$' || *str == '~' || *str == '*')
			return (true);
		else if (*str == '"')
		{
			if (dquote_has_exp(&str))
				return (true);
		}
		else if (*str == '\'')
			squote_has_exp(&str);
		str++;
	}
	return (false);
}

static t_strlst	*expand_variables(t_strlst *lst, t_shell *shell)
{
	t_strlst	*previous;
	t_strlst	*ptr;

	ptr = lst;
	previous = NULL;
	while (ptr)
	{
		if (has_expansion(ptr->str))
		{
			if (ft_strchr(ptr->str, '~'))
				tilde_expansion(&ptr->str, shell);
			if (ft_strchr(ptr->str, '$'))
				parameter_expansion(&ptr->str, shell);
			if (!word_splitting(&lst, &ptr, &previous, shell))
				continue ;
			filename_expansion(&ptr->str, shell);
		}
		quote_removal(&ptr->str, shell);
		previous = ptr;
		ptr = ptr->next;
	}
	return (lst);
}

void	perform_expansions(char ***strv, t_shell *shell)
{
	t_strlst	*lst;

	lst = strv_to_strlst(*strv);
	ft_free_null_strv(strv);
	lst = expand_variables(lst, shell);
	*strv = strlst_to_strv(lst);
	free_strlst(&lst);
}
