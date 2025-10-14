/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:03:13 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 23:25:33 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_node **stack)
{
	t_node	*last_node;
	t_node	*penult_node;

	last_node = ft_get_last_node(stack);
	if (!last_node || last_node == *stack)
		return ;
	penult_node = ft_get_penult_node(stack, &last_node);
	if (!penult_node)
		return ;
	last_node->next = *stack;
	*stack = last_node;
	penult_node->next = NULL;
}

void	rra(t_node **stack, int exec)
{
	ft_reverse_rotate(stack);
	if (exec != CHECKER)
		ft_printf("rra\n");
}

void	rrb(t_node **stack, int exec)
{
	ft_reverse_rotate(stack);
	if (exec != CHECKER)
		ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b, int exec)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (exec != CHECKER)
		ft_printf("rrr\n");
}
