/* ************************************************************************** */
/*                                                                            */
/*   5_cmd_options.c                                      :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:38:16 by afocant           #+#    #+#             */
/*   Updated: 2025/03/19 18:22:34 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "lexer.h"

static int	count_strs(char **strv)
{
	int	n;

	n = 0;
	while (*strv)
	{
		n++;
		strv++;
	}
	return (n);
}

static char	*copy_strv(char **old, char **new)
{
	char	*tmp;

	tmp = *old;
	while (*old)
	{
		*new = ft_strdup(*old);
		if (!*new)
			return (NULL);
		new++;
		old++;
	}
	*new = NULL;
	return (tmp);
}

char	*realloc_cmd_name(t_token **token, char *str, char ***name, t_shell *sh)
{
	int		strcount;
	char	**new;

	strcount = count_strs(*name);
	new = malloc(sizeof(char *) * (strcount + 2));
	if (!new)
		return (syntax_malloc_failed(sh));
	if (!copy_strv(*name, new))
	{
		ft_free_strv(new);
		return (syntax_malloc_failed(sh));
	}
	new[strcount] = ft_strdup(str);
	if (!new[strcount])
	{
		ft_free_strv(new);
		return (syntax_malloc_failed(sh));
	}
	new[++strcount] = NULL;
	ft_free_strv(*name);
	*name = new;
	advance(token);
	return (*new);
}
