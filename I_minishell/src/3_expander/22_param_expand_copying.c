/* ************************************************************************** */
/*                                                                            */
/*   21_param_expand2.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:26:32 by afocant           #+#    #+#             */
/*   Updated: 2025/03/31 21:46:49 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

static size_t	get_var_len(char *var)
{
	size_t	i;

	i = 0;
	while (*var)
	{
		if (*var == '\'' || *var == '"')
			i++;
		i++;
		var++;
	}
	return (i);
}

static void	count_to_closing_quote(char **str, size_t *total_len)
{
	(*total_len)++;
	(*str)++;
	while (**str != '\'')
	{
		(*total_len)++;
		(*str)++;
	}
	(*total_len)++;
	(*str)++;
}

static void	find_len_expand_value(char **str, size_t *total_len, t_shell *shell)
{
	char	*param_word;
	char	*value;

	param_word = get_param_w(*str, shell);
	if (!*param_word)
		(*total_len)++;
	value = get_expanded_value(param_word, shell);
	*total_len += get_var_len(value);
	*str += ft_strlen(param_word) + 1;
	free(param_word);
	free(value);
}

static void	count_in_dquote(char **str, size_t *total_len, t_shell *shell)
{
	(*total_len)++;
	(*str)++;
	while (**str && **str != '"')
	{
		if (**str == '$')
			find_len_expand_value(str, total_len, shell);
		else
		{
			(*total_len)++;
			(*str)++;
		}
	}
	(*total_len)++;
	(*str)++;
}

size_t	get_expansion_len(char *str, t_shell *shell)
{
	size_t	total_len;

	total_len = 0;
	while (*str)
	{
		if (*str == '"')
			count_in_dquote(&str, &total_len, shell);
		else if (*str == '\'')
			count_to_closing_quote(&str, &total_len);
		else if (*str == '$')
			find_len_expand_value(&str, &total_len, shell);
		else
		{
			total_len++;
			str++;
		}
	}
	return (total_len);
}
