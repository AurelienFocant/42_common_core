/* ************************************************************************** */
/*                                                                            */
/*   3_word_splitting.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:02:56 by afocant           #+#    #+#             */
/*   Updated: 2025/04/01 13:11:14 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

static t_strlst	*delete_node(t_strlst **node, t_strlst **prev)
{
	t_strlst	*tmp;

	tmp = (*node);
	if (*prev)
		(*prev)->next = (*node)->next;
	(*node) = (*node)->next;
	free(tmp->str);
	free(tmp);
	return (*node);
}

static t_strlst	*del_empty_node(t_strlst **lst, t_strlst **ptr, t_strlst **prev)
{
	if (*lst == *ptr)
	{
		(*ptr) = (*ptr)->next;
		return (delete_node(lst, prev));
	}
	else
		return (delete_node(ptr, prev));
}

static void	replace_first_node(t_strlst *ptr, char **split, t_shell *shell)
{
	free(ptr->str);
	ptr->str = ft_strdup(*split);
	if (!ptr->str)
	{
		ft_free_null_strv(&split);
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, shell);
	}
}

static void	insert_new_node(t_strlst *ptr, char **split, char *str, t_shell *sh)
{
	t_strlst	*node;

	node = malloc(sizeof(t_strlst));
	if (!node)
	{
		ft_free_null_strv(&split);
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, sh);
	}
	node->str = ft_strdup(str);
	if (!node->str)
	{
		free(node);
		ft_free_null_strv(&split);
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, sh);
	}
	node->next = ptr->next;
	ptr->next = node;
	ptr = ptr->next;
}

t_strlst	*word_splitting(
		t_strlst **head,
		t_strlst **lst,
		t_strlst **previous,
		t_shell *shell)
{
	char		**split;
	int			n;

	split = split_words((*lst)->str, ' ', shell);
	if (!split)
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, shell);
	if (!*split)
	{
		free(split);
		return (del_empty_node(head, lst, previous));
	}
	n = 0;
	while (split[n])
	{
		if (n == 0)
			replace_first_node((*lst), split, shell);
		else
			insert_new_node((*lst), split, split[n], shell);
		n++;
	}
	ft_free_null_strv(&split);
	return (*lst);
}
