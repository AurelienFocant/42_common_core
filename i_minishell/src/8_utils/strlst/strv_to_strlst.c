/* ************************************************************************** */
/*                                                                            */
/*   strv_to_strlst.c                                     :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:42:36 by afocant           #+#    #+#             */
/*   Updated: 2025/03/20 12:05:54 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

t_strlst	*build_strlst(char *str)
{
	t_strlst	*node;

	node = malloc(sizeof(t_strlst));
	if (!node)
		return (NULL);
	node->str = ft_strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

t_strlst	*strlstlast(t_strlst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	strlstadd_back(t_strlst **lst, t_strlst *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		strlstlast(*lst)->next = new;
	else
		*lst = new;
}

t_strlst	*strv_to_strlst(char **strv)
{
	t_strlst	*strlst;
	t_strlst	*new_node;

	strlst = NULL;
	new_node = NULL;
	while (*strv)
	{
		new_node = build_strlst(*strv);
		if (!new_node)
		{
			free_strlst(&strlst);
			return (NULL);
		}
		strlstadd_back(&strlst, new_node);
		strv++;
	}
	return (strlst);
}
