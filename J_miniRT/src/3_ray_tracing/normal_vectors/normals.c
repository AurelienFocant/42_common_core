/* ************************************************************************** */
/*                                                                            */
/*   normals.c                                            :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/24 21:20:12 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	normal_at_s(t_point p)
{
	return (vector(p.x, p.y, p.z));
}

t_vec	normal_at_pl(void)
{
	return (vector(0, 1, 0));
}

t_vec	normal_at_cu(t_point p)
{
	float	maxc;

	maxc = max(fabs(p.x), fabs(p.y), fabs(p.z));
	if (is_float_equal(maxc, fabs(p.x), EPSILON))
		return (vector(p.x, 0, 0));
	else if (is_float_equal(maxc, fabs(p.y), EPSILON))
		return (vector(0, p.y, 0));
	return (vector(0, 0, p.z));
}

t_vec	normal_at(t_object o, t_point world_point)
{
	t_point	object_point;
	t_vec	object_normal;
	t_vec	world_normal;

	object_point = multi_mat4_tuple(inverse_mat4(o.trans), world_point);
	object_normal = vector(0, 0, 0);
	if (o.type == SPHERE)
		object_normal = normal_at_s(object_point);
	else if (o.type == PLANE)
		object_normal = normal_at_pl();
	else if (o.type == CYLINDER)
		object_normal = normal_at_cy(o, object_point);
	else if (o.type == CONE)
		object_normal = normal_at_co(o, object_point);
	else if (o.type == CUBE)
		object_normal = normal_at_cu(object_point);
	world_normal = multi_mat4_tuple(
			transpose_mat4(inverse_mat4(o.trans)),
			object_normal);
	world_normal.w = 0;
	return (normalize_tuple(world_normal));
}
