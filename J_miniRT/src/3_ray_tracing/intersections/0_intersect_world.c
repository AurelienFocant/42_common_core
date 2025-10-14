/* ************************************************************************** */
/*                                                                            */
/*   0_intersect_world.c                                  :::      ::::::::   */
/*   0_intersect_world.c                                :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/25 23:38:32 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

t_intersection	*hit(t_intersections *xs)
{
	t_intersections	*inter;
	t_intersection	*res;

	if (!xs)
		return (NULL);
	inter = xs;
	res = xs->hit;
	inter = inter->next;
	while (inter)
	{
		if (res->t == 0 || is_float_equal(res->t, 0., EPSILON)
			|| ((res->t > inter->hit->t
					&& (inter->hit->t > 0.
						|| is_float_equal(inter->hit->t, 0., EPSILON)))
				|| (res->t < 0. && res->t < inter->hit->t))
		)
			res = inter->hit;
		inter = inter->next;
	}
	if (res->t < 0.)
		return (NULL);
	return (res);
}

t_intersection	*intersection(float t, t_object *obj)
{
	t_intersection	*inter;

	inter = malloc(sizeof(t_intersection));
	if (inter == NULL)
		return (NULL);
	inter->t = t;
	inter->obj = obj;
	return (inter);
}

void	intersections(t_intersections **track, t_intersection *inter)
{
	t_intersections	*new_list_intersections;
	t_intersections	*last;

	new_list_intersections = malloc(sizeof(t_intersections));
	if (!new_list_intersections)
		return (ft_free_intersections(*track, false), (void) NULL);
	new_list_intersections->hit = inter;
	new_list_intersections->next = NULL;
	if (!track || !*track)
	{
		*track = new_list_intersections;
		new_list_intersections->prev = NULL;
		return ;
	}
	last = *track;
	while (last->next)
		last = last->next;
	new_list_intersections->prev = last;
	last->next = new_list_intersections;
}

t_intersections	*intersect_world(t_world *w, t_ray r)
{
	int				i;
	t_intersections	*xs;

	i = 0;
	xs = NULL;
	while (i < w->obj_count)
	{
		add_intersections(&w->obj[i], r, &xs);
		i++;
	}
	sort_intersections(&xs);
	return (xs);
}
