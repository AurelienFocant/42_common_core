/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:54 by afocant           #+#    #+#             */
/*   Updated: 2024/08/30 15:15:30 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_node_value(t_node *node)
{
	if (!node)
		return ;
	ft_printf("%i\n", node->value);
}

void	ft_print_list(t_node *stack)
{
	while (stack)
	{
		ft_print_node_value(stack);
		stack = stack->next;
	}
}

void	ft_print_stack(t_node *stack, char *name)
{
	ft_print_list(stack);
	ft_printf("%\ns----------\n", name);
}

void	ft_print_both_stacks(t_node *stack_a, t_node *stack_b)
{
	ft_printf("\nA B\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%i ", stack_a->value);
			stack_a = stack_a->next;
		}
		else
			ft_printf("  ");
		if (stack_b)
		{
			ft_printf("%i\n", stack_b->value);
			stack_b = stack_b->next;
		}
		else
			ft_printf(" \n");
	}
	ft_printf("\n");
}
