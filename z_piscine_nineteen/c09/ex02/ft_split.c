/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:17:32 by afocant           #+#    #+#             */
/*   Updated: 2024/02/29 20:17:15 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (c == *str)
			return (str);
		str++;
	}
	return (NULL);
}

int	ft_countstrs(char *str, char *sep)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_strchr(sep, *str))
			str++;
		if (*str && !ft_strchr(sep, *str))
		{
			count++;
			while (*str && !ft_strchr(sep, *str))
				str++;
		}
	}
	return (count);
}

int	ft_strlen_sep(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !ft_strchr(sep, str[i]))
		i++;
	return (i);
}

char	*ft_strdup(char *src, int n)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		str_count;
	int		string_index;
	int		len_substr;
	char	**split;

	str_count = ft_countstrs(str, charset);
	split = malloc(sizeof(char *) * (str_count + 1));
	if (split == NULL)
		return (NULL);
	string_index = 0;
	while (*str)
	{
		while (*str && ft_strchr(charset, *str))
			str++;
		if (*str && !ft_strchr(charset, *str))
		{
			len_substr = ft_strlen_sep(str, charset);
			split[string_index++] = ft_strdup(str, len_substr);
			while (*str && !ft_strchr(charset, *str))
				str++;
		}
	}
	split[string_index] = 0;
	return (split);
}
