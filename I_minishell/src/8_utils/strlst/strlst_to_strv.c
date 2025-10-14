/* ************************************************************************** */
/*                                                                            */
/*   strlst.c                                             :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 06:45:38 by afocant           #+#    #+#             */
/*   Updated: 2025/03/24 11:34:27 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>

static void	free_null_str(char **str)
{
	free(*str);
	*str = NULL;
}

void	free_null_strlst(t_strlst **lst)
{
	free(*lst);
	*lst = NULL;
}

void	free_strlst(t_strlst **strlst)
{
	t_strlst	*tmp;

	while (*strlst)
	{
		tmp = *strlst;
		*strlst = (*strlst)->next;
		free_null_str(&(tmp->str));
		free_null_strlst(&(tmp));
	}
	free_null_strlst(strlst);
}

static int	count_strs_strlst(t_strlst *strlst)
{
	int	n;

	n = 0;
	while (strlst)
	{
		n++;
		strlst = strlst->next;
	}
	return (n);
}

char	**strlst_to_strv(t_strlst *strlst)
{
	char	**strv;
	int		str_count;
	int		i;

	str_count = count_strs_strlst(strlst);
	strv = malloc(sizeof(char *) * (str_count + 1));
	if (!strv)
		return (NULL);
	i = 0;
	while (i < str_count)
	{
		strv[i] = ft_strdup(strlst->str);
		if (!strv[i])
		{
			ft_free_null_strv(&strv);
			return (NULL);
		}
		i++;
		strlst = strlst->next;
	}
	strv[i] = NULL;
	return (strv);
}
