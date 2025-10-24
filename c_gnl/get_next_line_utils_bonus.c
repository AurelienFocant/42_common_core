/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:23:17 by afocant           #+#    #+#             */
/*   Updated: 2024/05/23 19:48:47 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free_and_null(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (--i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char) c)
		if (*s++ == '\0')
			return (NULL);
	return ((char *) s);
}

char	*ft_extract_line(char *stash)
{
	size_t	len;
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1 + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_trim_stash(char *stash, char *start)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(start);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (ft_free_and_null(&stash));
	i = 0;
	while (i < len)
		res[i++] = *start++;
	res[i] = '\0';
	if (!*res)
		ft_free_and_null(&res);
	ft_free_and_null(&stash);
	return (res);
}
