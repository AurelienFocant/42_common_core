/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:45 by afocant           #+#    #+#             */
/*   Updated: 2024/09/04 22:54:56 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(char **argv, t_node **stack_a)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		ft_create_node(ft_atoi(argv[i]), stack_a);
		i++;
	}
}

void	ft_create_node(int value, t_node **stack_a)
{
	t_node	*new_node;
	t_node	*ptr;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		ft_free_lists(*stack_a, NULL);
		ft_error_exit("Error creating a node", 3);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->target = NULL;
	new_node->cost = -1;
	if (!*stack_a)
		*stack_a = new_node;
	else
	{
		ptr = *stack_a;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_node;
	}
}

void	ft_free_linkedlist(t_node *lst)
{
	t_node	*ptr;

	while (lst)
	{
		ptr = lst;
		lst = lst->next;
		free(ptr);
	}
}

void	ft_free_lists(t_node *stack_a, t_node *stack_b)
{
	ft_free_linkedlist(stack_a);
	ft_free_linkedlist(stack_b);
}
