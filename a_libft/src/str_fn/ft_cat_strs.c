/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:09:49 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:43:38 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*cat_s1_s2(char *res, char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (s1)
	{
		while (*s1)
			res[i++] = *s1++;
	}
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

char	*cat_strs(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!res)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	res = cat_s1_s2(res, s1, s2);
	if (s1)
		free(s1);
	return (res);
}

char	*ft_cat_strs(int nb, ...)
{
	char	*res;
	va_list	args;

	res = NULL;
	va_start(args, nb);
	while (nb--)
	{
		res = cat_strs(res, va_arg(args, char *));
		if (!res)
			return (NULL);
	}
	va_end(args);
	return (res);
}
