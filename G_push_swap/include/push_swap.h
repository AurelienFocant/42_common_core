/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:15 by afocant           #+#    #+#             */
/*   Updated: 2024/09/24 12:05:53 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

# define FALSE 0
# define TRUE 1

# define A 0
# define B 1

# define CHECKER 0
# define PRINT 1

typedef struct s_node
{
	int				value;
	struct s_node	*target;
	int				cost;
	struct s_node	*next;
}					t_node;

/*----------------  checker_main_bonus.c  ---------------*/
void			ft_checker_error(t_node **stack_a, t_node **stack_b);
void			ft_execute_cmd(char *line, t_node **stack_a, t_node **stack_b);
void			ft_read_operations(t_node **stack_a, t_node **stack_b);
int				ft_check_if_sorted(
					unsigned int len_a,
					t_node *stack_a,
					t_node *stack_b);

/*----------------  rotate.c  ---------------*/
void			ft_rotate(t_node **stack);
void			ra(t_node **stack, int exec);
void			rb(t_node **stack, int exec);
void			rr(t_node **stack_a, t_node **stack_b, int exec);

/*----------------  push.c  ---------------*/
void			ft_push(t_node **stack_from, t_node **stack_to);
void			pb(t_node **stack_a, t_node **stack_b, int exec);
void			pa(t_node **stack_b, t_node **stack_a, int exec);

/*----------------  reverse_rotate.c  ---------------*/
void			ft_reverse_rotate(t_node **stack);
void			rra(t_node **stack, int exec);
void			rrb(t_node **stack, int exec);
void			rrr(t_node **stack_a, t_node **stack_b, int exec);

/*----------------  swap.c  ---------------*/
void			ft_swap(t_node **stack);
void			sa(t_node **stack_a, int exec);
void			sb(t_node **stack_b, int exec);
void			ss(t_node **stack_a, t_node **stack_b, int exec);

/*----------------  set_targets.c  ---------------*/
void			ft_find_target_bigger(t_node *node, t_node **stack);
void			ft_set_targets_bigger(t_node **stack_from, t_node **stack_to);
void			ft_find_target_smaller(t_node *node, t_node **stack);
void			ft_set_targets_smaller(t_node **stack_from, t_node **stack_to);

/*----------------  push_cheapest.c  ---------------*/
void			ft_rotate_stack(t_node **stack, t_node *node, int name);
void			ft_rotate_both_stacks(
					t_node *node,
					t_node **stack_a,
					t_node **stack_b);
t_node			*ft_find_cheapest(t_node **stack);
void			ft_push_cheapest(
					t_node **stack_from,
					t_node **stack_to,
					int name_from,
					int name_to);

/*----------------  turk_algo.c  ---------------*/
unsigned int	ft_find_position(t_node *node, t_node *stack);
int				ft_is_above_median(t_node *node, t_node *stack);
void			ft_last_rotate(t_node **stack_a);
void			ft_turk_algo(t_node **stack_a, t_node **stack_b);

/*----------------  sort_utils.c  ---------------*/
t_node			*ft_find_max(t_node *stack);
t_node			*ft_find_min(t_node *stack);
int				ft_sort_three(t_node **stack);
int				ft_sort_two(t_node **stack);
int				ft_is_sorted(t_node *stack);

/*----------------  parse_args.c  ---------------*/
size_t			ft_count_args(char **av);
char			**ft_parse_str(char *str);
char			**ft_parse_args(char **argv, size_t size);

/*----------------  errors_utils.c  ---------------*/
void			ft_error_exit(char *msg, int exitcode);
void			ft_free_null1(void *ptr);
void			ft_free_strv1(char **av);
void			ft_free_error_exit(char **av, char *msg, int exitcode);

/*----------------  check_args.c  ---------------*/
int				ft_is_str_nbr(char *str);
int				ft_check_non_integers(char **argv);
int				ft_check_duplicates(char **argv, size_t size);
char			**ft_check_arg_errors(int argc, char **argv);

/*----------------  print_list.c  ---------------*/
void			ft_print_node_value(t_node *node);
void			ft_print_list(t_node *stack);
void			ft_print_stack(t_node *stack, char *name);
void			ft_print_both_stacks(t_node *stack_a, t_node *stack_b);

/*----------------  list_init.c  ---------------*/
void			ft_init_stack(char **argv, t_node **stack_a);
void			ft_create_node(int value, t_node **stack_a);
void			ft_free_linkedlist(t_node *lst);
void			ft_free_lists(t_node *stack_a, t_node *stack_b);

/*----------------  search_list.c  ---------------*/
t_node			*ft_get_last_node(t_node **stack);
t_node			*ft_get_penult_node(t_node **stack, t_node **last_node);
unsigned int	ft_stacklen(t_node *stack);

/*----------------  set_costs.c  ---------------*/
unsigned int	ft_return_bigger_cost(unsigned int cost1, unsigned int cost2);
unsigned int	ft_count_moves_to_top(t_node *node, t_node *stack);
int				ft_find_cost(t_node *node, t_node **stack_a, t_node **stack_b);
void			ft_set_costs(t_node **stack_a, t_node **stack_b);
int				ft_double_rotate_possible(
					t_node *cheapest,
					t_node *stack_from,
					t_node *stack_to);

#endif
