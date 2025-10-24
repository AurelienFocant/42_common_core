/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:58 by afocant           #+#    #+#             */
/*   Updated: 2024/08/22 23:14:06 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_get_last_node(t_node **stack)
{
	t_node	*ptr;

	if (!*stack)
		return (NULL);
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

t_node	*ft_get_penult_node(t_node **stack, t_node **last_node)
{
	t_node	*ptr;

	ptr = *stack;
	while (ptr->next != *last_node)
		ptr = ptr->next;
	return (ptr);
}

unsigned int	ft_stacklen(t_node *stack)
{
	unsigned int	len;
	t_node			*ptr;

	len = 0;
	ptr = stack;
	while (ptr)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}
