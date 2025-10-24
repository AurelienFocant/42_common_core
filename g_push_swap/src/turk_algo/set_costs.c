/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:48:37 by afocant           #+#    #+#             */
/*   Updated: 2024/09/04 21:13:28 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_return_bigger_cost(unsigned int cost1, unsigned int cost2)
{
	if (cost1 > cost2)
		return (cost1);
	else
		return (cost2);
}

int	ft_double_rotate_possible(
	t_node *cheapest,
	t_node *stack_from,
	t_node *stack_to)
{
	int	from;
	int	to;

	from = ft_is_above_median(cheapest, stack_from);
	to = ft_is_above_median(cheapest->target, stack_to);
	if (from == to)
		return (TRUE);
	else
		return (FALSE);
}

unsigned int	ft_count_moves_to_top(t_node *node, t_node *stack)
{
	unsigned int	position;
	unsigned int	len;
	unsigned int	median;

	len = ft_stacklen(stack);
	median = len / 2;
	position = ft_find_position(node, stack);
	if (position <= median)
		return (position);
	else
		return (len - position);
}

int	ft_find_cost(t_node *node, t_node **stack_a, t_node **stack_b)
{
	unsigned int	cost1;
	unsigned int	cost2;

	cost1 = ft_count_moves_to_top(node, *stack_a);
	cost2 = ft_count_moves_to_top(node->target, *stack_b);
	if (ft_double_rotate_possible(node, *stack_a, *stack_b))
		return (ft_return_bigger_cost(cost1, cost2));
	else
		return (cost1 + cost2);
}

void	ft_set_costs(t_node **stack_a, t_node **stack_b)
{
	t_node	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		ptr->cost = ft_find_cost(ptr, stack_a, stack_b);
		ptr = ptr->next;
	}
}
