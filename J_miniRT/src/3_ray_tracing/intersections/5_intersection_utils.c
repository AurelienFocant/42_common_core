/* ************************************************************************** */
/*                                                                            */
/*   5_intersection_utils.c                               :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	is_intersections_sorted(bool *sorted, t_intersections *node)
{
	if (node->next == NULL)
		*sorted = true;
	while (node->next)
	{
		if (node->hit->t < node->next->hit->t
			|| is_float_equal(node->hit->t,
				node->next->hit->t, EPSILON) == true)
			*sorted = true;
		else
			*sorted = false;
		node = node->next;
	}
}

void	sort_intersections(t_intersections **xs)
{
	t_intersections	*node;
	bool			sorted;
	t_intersection	*hit;

	if (!xs || !*xs)
		return ;
	sorted = false;
	while (!sorted)
	{
		node = *xs;
		while (node)
		{
			if (node->next)
			{
				if (node->hit->t > node->next->hit->t)
				{
					hit = node->hit;
					node->hit = node->next->hit;
					node->next->hit = hit;
				}
			}
			node = node->next;
		}
		is_intersections_sorted(&sorted, *xs);
	}
}

void	add_intersections(t_object *o, t_ray r, t_intersections **xs)
{
	t_intersect		x;
	t_intersection	*inter;
	int				count;

	x = intersect_object(*o, r);
	count = 0;
	while (count < x.count)
	{
		inter = intersection(x.points[count], o);
		if (!inter)
			return (ft_free_intersections(*xs, false), (void) NULL);
		intersections(xs, inter);
		count++;
	}
}
