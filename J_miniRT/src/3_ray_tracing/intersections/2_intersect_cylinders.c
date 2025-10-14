/* ************************************************************************** */
/*                                                                            */
/*   2_intersect_cylinders.c                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_cap(t_ray r, float t)
{
	float	x;
	float	z;
	float	res;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	res = powf(x, 2) + powf(z, 2);
	if (res < 1 || is_float_equal(res, 1, EPSILON))
		return (true);
	return (false);
}

t_intersect	intersect_caps(t_object o, t_ray r, t_intersect x)
{
	float	t;

	if (!o.cy.closed || is_float_equal(r.direction.y, 0., EPSILON))
		return (x);
	t = (o.cy.min - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
	{
		x.points[x.count] = t;
		x.count++;
	}
	t = (o.cy.max - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
	{
		x.points[x.count] = t;
		x.count++;
	}
	return (x);
}

t_intersect	intersect_cylinder_limits(t_object o, t_ray r, float t, t_intersect x)
{
	float	y;

	y = r.origin.y + t * r.direction.y;
	if (o.cy.min < y && y < o.cy.max)
	{
		if (!is_float_equal(o.cy.min, y, EPSILON))
		{
			if (!is_float_equal(o.cy.max, y, EPSILON))
			{
				x.points[x.count] = t;
				x.count++;
			}
		}
	}
	return (x);
}

t_intersect	intersect_cylinder(t_object o, t_ray r, t_discriminant disc, t_intersect x)
{
	float			t0;
	float			t1;

	t0 = ((float) -disc.b - sqrtf(disc.discriminant)) / (2. * disc.a);
	t1 = ((float) -disc.b + sqrtf(disc.discriminant)) / (2. * disc.a);
	if (t0 > t1)
		swapf(&t0, &t1);
	x = intersect_cylinder_limits(o, r, t0, x);
	x = intersect_cylinder_limits(o, r, t1, x);
	return (x);
}

t_intersect	intersect_cy(t_object o, t_ray r)
{
	t_discriminant	disc;
	t_intersect		x;

	x = empty_intersect(o.id);
	disc.a = powf(r.direction.x, 2.) + powf(r.direction.z, 2.0);
	if (is_float_equal(disc.a, 0., EPSILON))
		return (intersect_caps(o, r, x));
	disc.b = 2. * r.origin.x * r.direction.x
		+ 2. * r.origin.z * r.direction.z;
	disc.c = powf(r.origin.x, 2.) + powf(r.origin.z, 2.) - 1;
	disc.discriminant = (powf(disc.b, 2.)) - 4. * disc.a * disc.c;
	if (disc.discriminant < 0)
		return (x);
	x = intersect_cylinder(o, r, disc, x);
	x = intersect_caps(o, r, x);
	return (x);
}
