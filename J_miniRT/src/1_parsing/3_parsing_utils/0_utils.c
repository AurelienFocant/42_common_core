/* ************************************************************************** */
/*                                                                            */
/*   0_utils.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	consume_paren(char **line)
{
	if (**line && (**line == '(' || **line == ')'))
		(*line)++;
}

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	return (i);
}

bool	match(char *s, char *target)
{
	if (!s || !target)
		return (false);
	if (*s && *target)
	{
		if (len(target) == 1)
		{
			if (*s == *target
				&& ft_isspace(*(s + 1)))
				return (true);
			return (false);
		}
		if (len(target) == 2)
		{
			if (*s == *target
				&& *(s + 1) == *(target + 1)
				&& ft_isspace(*(s + 2)))
				return (true);
			return (false);
		}
	}
	return (false);
}

int	first_word(char *s)
{
	if (!s)
		return (-1);
	while (*s && ft_isspace(*s))
		s++;
	if (match(s, "C"))
		return (CAMERA);
	if (match(s, "A"))
		return (AMBIENT);
	if (match(s, "L"))
		return (LIGHT);
	if (match(s, "sp")
		|| match(s, "cy") || match(s, "pl")
		|| match(s, "co") || match(s, "cu"))
		return (OBJECT);
	if (match(s, "#"))
		return (COMMENT);
	return (-1);
}

int	object_kind(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	if (match(s, "sp"))
		return (SPHERE);
	if (match(s, "pl"))
		return (PLANE);
	if (match(s, "cy"))
		return (CYLINDER);
	if (match(s, "co"))
		return (CONE);
	if (match(s, "cu"))
		return (CUBE);
	return (-1);
}
