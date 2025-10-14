/* ************************************************************************** */
/*                                                                            */
/*   31_word_splitting_split.c                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:36:44 by afocant           #+#    #+#             */
/*   Updated: 2025/04/01 13:36:34 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

static void	go_to_next_quote(char **s)
{
	char	quote;

	quote = **s;
	(*s)++;
	while (**s != quote)
		(*s)++;
	(*s)++;
}

static int	count_strs(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && (ft_isquote(*s) || *s != c))
		{
			count++;
			if (ft_isquote(*s))
				go_to_next_quote(&s);
			while (*s && *s != c)
			{
				if (ft_isquote(*s))
					go_to_next_quote(&s);
				else if (*s)
					s++;
			}
		}
	}
	return (count);
}

char	**split_words(char *s, char c, t_shell *shell)
{
	int		strs_count;
	char	**split_s;

	strs_count = count_strs(s, c);
	split_s = malloc(sizeof(char *) * (strs_count + 1));
	if (!split_s)
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, shell);
	split_s[strs_count] = NULL;
	if (!fill_strs(s, c, split_s, strs_count))
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, shell);
	return (split_s);
}
