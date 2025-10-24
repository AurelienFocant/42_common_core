/* ************************************************************************** */
/*                                                                            */
/*   refractive_index.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_intersections	*last_containers(t_intersections *containers)
{
	while (containers->next)
		containers = containers->next;
	return (containers);
}

void	is_hit_in_containers(t_intersections **containers, t_intersection *hit)
{
	t_intersections	*tmp;

	if (!containers || !*containers)
		return (intersections(containers, hit), (void) NULL);
	tmp = *containers;
	while (tmp)
	{
		if (tmp->hit->obj == hit->obj)
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			else
				*containers = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
	intersections(containers, hit);
}

void	refractive_n2_index(t_comps *comps, t_intersections *containers, t_intersections *last_c)
{
	if (!containers)
		comps->n2 = 1.0;
	else
	{
		last_c = last_containers(containers);
		comps->n2 = last_c->hit->obj->material.refractive_index;
	}
}

void	prepare_refractive_index(t_comps *comps, t_intersection *hit, t_intersections *xs)
{
	t_intersections	*containers;
	t_intersections	*last_c;

	containers = NULL;
	while (xs)
	{
		if (xs->hit == hit)
		{
			if (!containers)
				comps->n1 = 1.0;
			else
			{
				last_c = last_containers(containers);
				comps->n1 = last_c->hit->obj->material.refractive_index;
			}
		}
		is_hit_in_containers(&containers, xs->hit);
		if (xs->hit == hit)
			refractive_n2_index(comps, containers, last_c);
		xs = xs->next;
	}
	ft_free_intersections(containers, true);
}
