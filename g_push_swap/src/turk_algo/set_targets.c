/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:36 by afocant           #+#    #+#             */
/*   Updated: 2024/09/30 15:42:51 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target_bigger(t_node *node, t_node **stack)
{
	t_node	*ptr;

	node->target = NULL;
	ptr = *stack;
	while (ptr)
	{
		if (ptr->value > node->value && (!node->target || ptr->value < node->target->value))
			node->target = ptr;
		ptr = ptr->next;
	}
	if (!node->target)
		node->target = ft_find_min(*stack);
}

void	ft_set_targets_bigger(t_node **stack_from, t_node **stack_to)
{
	t_node	*ptr;

	ptr = *stack_from;
	while (ptr)
	{
		ft_find_target_bigger(ptr, stack_to);
		ptr = ptr->next;
	}
}

void	ft_find_target_smaller(t_node *node, t_node **stack)
{
	t_node	*ptr;

	node->target = NULL;
	ptr = *stack;
	while (ptr)
	{
		if (ptr->value < node->value && (!node->target || ptr->value > node->target->value))
			node->target = ptr;
		ptr = ptr->next;
	}
	if (!node->target)
		node->target = ft_find_max(*stack);
}

void	ft_set_targets_smaller(t_node **stack_from, t_node **stack_to)
{
	t_node	*ptr;

	ptr = *stack_from;
	while (ptr)
	{
		ft_find_target_smaller(ptr, stack_to);
		ptr = ptr->next;
	}
}
