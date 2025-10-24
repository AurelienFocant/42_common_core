/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:03:23 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 23:27:12 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*ptr;

	if (!*stack || !(*stack)->next)
		return ;
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	ptr->next = *stack;
	*stack = ptr;
}

void	sa(t_node **stack_a, int exec)
{
	ft_swap(stack_a);
	if (exec != CHECKER)
		ft_printf("sa\n");
}

void	sb(t_node **stack_b, int exec)
{
	ft_swap(stack_b);
	if (exec != CHECKER)
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b, int exec)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (exec != CHECKER)
		ft_printf("ss\n");
}
