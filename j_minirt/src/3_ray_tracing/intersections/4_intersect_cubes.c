/* ************************************************************************** */
/*                                                                            */
/*   4_intersect_cubes.c                                  :::      ::::::::   */
/*   4_intersect_cubes.c                                :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/25 22:47:47 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_pair	check_axis(float origin, float direction)
{
	float	tmin_numerator;
	float	tmax_numerator;
	t_pair	t;

	tmin_numerator = (-1 - origin);
	tmax_numerator = (1 - origin);
	if (fabs(direction) > EPSILON
		|| is_float_equal(fabs(direction), 0., EPSILON))
	{
		t.u = tmin_numerator / direction;
		t.v = tmax_numerator / direction;
	}
	else
	{
		t.u = tmin_numerator * INFINITY;
		t.v = tmax_numerator * INFINITY;
	}
	if (t.u == -0.f)
		t.u = 0.f;
	if (t.v == -0.f)
		t.v = 0.f;
	if (t.u > t.v)
	{
		tmin_numerator = t.u;
		t.u = t.v;
		t.v = tmin_numerator;
	}
	return (t);
}

float	min(float v1, float v2, float v3)
{
	if (v1 <= v2 && v1 <= v3)
		return (v1);
	else if (v2 <= v1 && v2 <= v3)
		return (v2);
	return (v3);
}

float	max(float v1, float v2, float v3)
{
	if (v1 >= v2 && v1 >= v3)
		return (v1);
	else if (v2 >= v1 && v2 >= v3)
		return (v2);
	return (v3);
}

t_intersect	intersect_cu(t_object o, t_ray r)
{
	t_pair		x;
	t_pair		y;
	t_pair		z;
	t_pair		res;
	t_intersect	xs;

	x = check_axis(r.origin.x, r.direction.x);
	y = check_axis(r.origin.y, r.direction.y);
	z = check_axis(r.origin.z, r.direction.z);
	res.u = max(x.u, y.u, z.u);
	res.v = min(x.v, y.v, z.v);
	xs.count = 0;
	if (res.u > res.v)
		return (xs);
	xs.points[0] = res.u;
	xs.points[1] = res.v;
	xs.count = 2;
	xs.object_id = o.id;
	return (xs);
}
