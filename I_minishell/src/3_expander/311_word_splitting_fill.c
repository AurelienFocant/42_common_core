/* ************************************************************************** */
/*                                                                            */
/*   311_word_splitting_fill.c                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:34:11 by afocant           #+#    #+#             */
/*   Updated: 2025/04/01 13:47:25 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **split_s, int i)
{
	int		j;

	j = 0;
	while (j < i)
		free(split_s[j++]);
	free(split_s);
	return (NULL);
}

static int	len_strsep(char *s, char c)
{
	int		i;
	char	quote;

	i = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '"')
		{
			quote = *s;
			s++;
			i++;
			while (*s++ != quote)
				i++;
			i++;
			continue ;
		}
		if (*s == c)
			break ;
		i++;
		s++;
	}
	return (i);
}

static void	go_to_next_quote(char **s)
{
	char	quote;

	quote = **s;
	(*s)++;
	while (**s != quote)
		(*s)++;
	(*s)++;
}

char	**fill_strs(char *s, char c, char **split_s, int strs_count)
{
	int		i;

	i = 0;
	while (i < strs_count)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			split_s[i] = ft_substr(s, 0, len_strsep(s, c));
			if (!split_s[i])
				return (free_split(split_s, i));
			i++;
			while (*s && *s != c)
			{
				if (ft_isquote(*s))
					go_to_next_quote(&s);
				else if (*s)
					s++;
			}
		}
	}
	return (split_s);
}
