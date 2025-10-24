/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:19:13 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 23:28:27 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_max(t_node *stack)
{
	t_node	*res;

	res = stack;
	while (stack)
	{
		if (stack->value > res->value)
			res = stack;
		stack = stack->next;
	}
	return (res);
}

t_node	*ft_find_min(t_node *stack)
{
	t_node	*res;

	res = stack;
	while (stack)
	{
		if (stack->value < res->value)
			res = stack;
		stack = stack->next;
	}
	return (res);
}

int	ft_sort_three(t_node **stack)
{
	t_node	*max;

	if (ft_is_sorted(*stack))
		return (TRUE);
	max = ft_find_max(*stack);
	if (*stack == max)
		ra(stack, PRINT);
	else if ((*stack)->next == max)
		rra(stack, PRINT);
	if (!ft_is_sorted(*stack))
		sa(stack, PRINT);
	return (TRUE);
}

int	ft_sort_two(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, PRINT);
	return (TRUE);
}

int	ft_is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}
