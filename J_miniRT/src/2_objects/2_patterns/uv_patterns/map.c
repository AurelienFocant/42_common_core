/* ************************************************************************** */
/*                                                                            */
/*   map.c                                                :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/24 21:41:40 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_pair	spherical_map(t_point p)
{
	float	theta;
	float	radius;
	float	phi;
	float	raw_u;
	t_pair	pair;

	theta = atan2f(p.x, p.z);
	radius = magnitude(vector(p.x, p.y, p.z));
	phi = acosf(p.y / radius);
	raw_u = theta / (2 * M_PI);
	pair.u = 1 - (raw_u + 0.5);
	pair.v = 1 - phi / M_PI;
	if (is_float_equal(pair.u, 0, EPSILON))
		pair.u = 0.;
	if (is_float_equal(pair.v, 0, EPSILON))
		pair.v = 0.;
	return (pair);
}

t_pair	planar_map(t_point p)
{
	t_pair	pair;

	pair.u = fmodf(p.x, 1);
	pair.v = fmodf(p.z, 1);
	return (pair);
}

t_pair	cylindrical_map(t_point p)
{
	float	theta;
	float	raw_u;
	t_pair	pair;

	theta = atan2f(p.x, p.z);
	raw_u = theta / (2 * M_PI);
	pair.u = 1 - (raw_u + 0.5);
	pair.v = fmodf(p.y, 1);
	return (pair);
}

int	face_form_point(t_point p)
{
	float	abs_x;
	float	abs_y;
	float	abs_z;
	float	coord;

	abs_x = fabs(p.x);
	abs_y = fabs(p.y);
	abs_z = fabs(p.z);
	coord = max(abs_x, abs_y, abs_z);
	if (coord == p.x)
		return (RIGHT);
	if (coord == -p.x)
		return (LEFT);
	if (coord == p.y)
		return (UP);
	if (coord == -p.y)
		return (DOWN);
	if (coord == p.z)
		return (FRONT);
	return (BACK);
}
