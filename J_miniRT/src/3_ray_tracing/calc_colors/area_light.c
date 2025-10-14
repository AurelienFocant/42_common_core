/* ************************************************************************** */
/*                                                                            */
/*   area_light.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

t_point	point_on_light(t_light light, int u, int v)
{
	t_point			result;

	if (u == 0 && v == 0)
	{
		result = add_tuple(light.corner, scalar_multi_tuple(0.5, light.uvec));
		result = add_tuple(result, scalar_multi_tuple(0.5, light.vvec));
		return (result);
	}
	result = add_tuple(light.corner,
			scalar_multi_tuple((u + light.jitter_by), light.uvec));
	result = add_tuple(result,
			scalar_multi_tuple((v + light.jitter_by), light.vvec));
	return (result);
}

float	intensity_at(t_world *w, t_point point, int which_light)
{
	float	total;
	int		u;
	int		v;
	t_point	light_position;

	v = 0;
	total = 0;
	if (w->lights[which_light].vsteps == 1
		&& w->lights[which_light].usteps == 1)
		return (!(is_in_shadow(w, point, w->lights[which_light].corner)));
	while (v < w->lights[which_light].vsteps)
	{
		u = 0;
		while (u < w->lights[which_light].usteps)
		{
			light_position = point_on_light(w->lights[which_light], u, v);
			if (is_in_shadow(w, point, light_position) == false)
				total += 1.;
			u++;
		}
		v++;
	}
	return (total / w->lights[which_light].samples);
}

bool	is_in_shadow(t_world *w, t_point p, t_point light_position)
{
	float			distance_to_light;
	t_vec			point_to_light;
	t_ray			ray_to_light;
	t_intersections	*world_intersections;
	t_intersection	*first_hit;

	point_to_light = sub_tuple(light_position, p);
	distance_to_light = magnitude(point_to_light);
	ray_to_light = ray(p, normalize_tuple(point_to_light));
	world_intersections = intersect_world(w, ray_to_light);
	first_hit = hit(world_intersections);
	if (first_hit && first_hit->t < distance_to_light)
		return (ft_free_intersections(world_intersections, false), true);
	ft_free_intersections(world_intersections, false);
	return (false);
}
