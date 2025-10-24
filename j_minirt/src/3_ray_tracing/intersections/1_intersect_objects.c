/* ************************************************************************** */
/*                                                                            */
/*   1_intersect_objects.c                                :::      ::::::::   */
/*   1_intersect_objects.c                              :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/20 23:42:30 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_intersect	empty_intersect(int object_id)
{
	t_intersect	x;

	x.count = 0;
	x.points[0] = 0;
	x.points[1] = 0;
	x.object_id = object_id;
	return (x);
}

t_intersect	intersect_sp(t_object o, t_ray r)
{
	t_intersect		x;
	t_vec			sphere_to_ray;
	t_discriminant	disc;

	x = empty_intersect(o.id);
	sphere_to_ray = sub_tuple(r.origin, o.s.origin);
	disc.a = dot_product(r.direction, r.direction);
	disc.b = 2.0 * (float) dot_product(r.direction, sphere_to_ray);
	disc.c = dot_product(sphere_to_ray, sphere_to_ray)
		- (o.s.radius * o.s.radius);
	disc.discriminant = (powf(disc.b, 2) - (4.0 * disc.a * disc.c));
	if (disc.discriminant < 0)
		return (x);
	x.count = 2;
	x.points[0] = ((-disc.b - sqrtf(disc.discriminant)) / (2 * disc.a));
	x.points[1] = ((-disc.b + sqrtf(disc.discriminant)) / (2 * disc.a));
	return (x);
}

t_intersect	intersect_pl(t_object o, t_ray r)
{
	t_intersect	x;

	x = empty_intersect(o.id);
	if (fabsf(r.direction.y) < EPSILON)
		return (x);
	x.count = 1;
	x.points[0] = -(r.origin.y) / r.direction.y;
	return (x);
}

t_intersect	intersect_object(t_object o, t_ray r)
{
	r = transform_r(r, inverse_mat4(o.trans));
	if (o.type == SPHERE)
		return (intersect_sp(o, r));
	if (o.type == PLANE)
		return (intersect_pl(o, r));
	if (o.type == CYLINDER)
		return (intersect_cy(o, r));
	if (o.type == CONE)
		return (intersect_co(o, r));
	if (o.type == CUBE)
		return (intersect_cu(o, r));
	return (intersect_sp(o, r));
}
