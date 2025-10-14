/* ************************************************************************** */
/*                                                                            */
/*   20_param_expand.c                                    :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:32:26 by afocant           #+#    #+#             */
/*   Updated: 2025/03/31 21:09:35 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

char	*get_expanded_value(char *param_word, t_shell *shell)
{
	char	*value;

	if (ft_strcmp("?", param_word) == EXIT_SUCCESS)
		value = ft_itoa(shell->exit_code);
	else
		value = ft_strdup(find_env_var_value((param_word), shell));
	if (!value)
	{
		free(param_word);
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, shell);
	}
	return (value);
}

static char	*get_param_end(char *s)
{
	++s;
	if (ft_isspace(*s))
		return (--s);
	if (*s == '?')
		return (++s);
	if (ft_isdigit(*s))
	{
		while (ft_isdigit(*s))
			s++;
		return (s);
	}
	while (*s && (ft_isalnum(*s) || *s == '_'))
		s++;
	return (s);
}

char	*get_param_w(char *s, t_shell *shell)
{
	char	*end;
	char	*word;

	end = get_param_end(s);
	if (end == s)
		word = ft_strdup("");
	else
		word = ft_substr(s + 1, 0, end - s - 1);
	if (!word)
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, shell);
	return (word);
}

void	parameter_expansion(char **str, t_shell *shell)
{
	size_t	total_len;
	char	*res;
	char	*s;

	s = *str;
	total_len = get_expansion_len(s, shell);
	res = ft_calloc((total_len + 1), sizeof(char));
	if (!res)
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, shell);
	param_exp(res, s, shell);
	free(*str);
	*str = res;
}
