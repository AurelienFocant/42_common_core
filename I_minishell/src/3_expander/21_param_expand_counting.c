/* ************************************************************************** */
/*                                                                            */
/*   param_expand.c                                       :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:20:52 by afocant           #+#    #+#             */
/*   Updated: 2025/03/31 21:55:23 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

static char	*copy_expanded_value(char **res, char *value)
{
	int		i;

	i = 0;
	while (value[i])
	{
		if (value[i] == '\'' || value[i] == '"')
		{
			**res = '\\';
			(*res)++;
		}
		**res = value[i++];
		(*res)++;
	}
	return (*res);
}

static void	expand_value(char **res, char **str, t_shell *shell)
{
	char	*value;
	char	*param_word;

	param_word = NULL;
	param_word = get_param_w(*str, shell);
	if (!*param_word)
	{
		**res = **str;
		(*res)++;
		(*str)++;
		free (param_word);
		return ;
	}
	value = get_expanded_value(param_word, shell);
	copy_expanded_value(res, value);
	*str += ft_strlen(param_word) + 1;
	free(value);
	free(param_word);
}

static void	copy_in_dquote(char **res, char **str, t_shell *shell)
{
	**res = **str;
	(*res)++;
	(*str)++;
	while (**str && **str != '"')
	{
		if (**str == '$')
			expand_value(res, str, shell);
		else
		{
			**res = **str;
			(*res)++;
			(*str)++;
		}
	}
	**res = **str;
	(*res)++;
	(*str)++;
}

static void	copy_in_squote(char **res, char **str)
{
	**res = **str;
	(*res)++;
	(*str)++;
	while (**str != '\'')
	{
		**res = **str;
		(*res)++;
		(*str)++;
	}
	**res = **str;
	(*res)++;
	(*str)++;
}

void	param_exp(char *res, char *str, t_shell *shell)
{
	while (*str)
	{
		if (*str == '"')
			copy_in_dquote(&res, &str, shell);
		else if (*str == '\'')
			copy_in_squote(&res, &str);
		else if (*str == '$')
			expand_value(&res, &str, shell);
		else
			*res++ = *str++;
	}
	*res = '\0';
}
