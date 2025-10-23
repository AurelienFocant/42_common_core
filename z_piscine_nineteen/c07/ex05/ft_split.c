/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:40:28 by afocant           #+#    #+#             */
/*   Updated: 2024/02/28 23:57:33 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(char *sep, char c)
{
	while (*sep)
	{
		if (*sep == c)
			return (sep);
		sep++;
	}
	return (NULL);
}

int	ft_count_strings(char *str, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (ft_strchr(sep, str[i]) != NULL))
			i++;
		while (str[i] && (ft_strchr(sep, str[i]) == NULL))
		{
			count++;
			while (str[i] && ft_strchr(sep, str[i]) == NULL)
				i++;
		}
	}
	return (count);
}

char	*ft_copy_substring(char *str, char *sep)
{
	int		len;
	int		i;
	char	*substring;

	len = 0;
	while (str[len] && !ft_strchr(sep, str[len]))
		len++;
	substring = malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = str[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

void	ft_fill_array(char **split, char *str, char *sep)
{
	int		string_index;

	string_index = 0;
	while (*str)
	{
		while (ft_strchr(sep, *str) && *str) 
			str++;
		if (!ft_strchr(sep, *str) && *str)
		{
			split[string_index++] = ft_copy_substring(str, sep);
			while (!ft_strchr(sep, *str) && *str)
				str++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		count;

	count = ft_count_strings(str, charset);
	split = malloc(sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	ft_fill_array(split, str, charset);
	split[count] = 0;
	return (split);
}

#include <stdio.h>

int main()
{
	char **split = ft_split("2irpFtIBNMwO8Fz7EeQjhU8QEEcqsJVDC", " F");

	while (*split)
		printf("%s\n", *split++);

/*
	int i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	*/
	//free(split);
}

