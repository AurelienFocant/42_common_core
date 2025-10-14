/* ************************************************************************** */
/*                                                                            */
/*   normals2.c                                           :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	normal_at_cy(t_object o, t_point p)
{
	float	dist;

	dist = powf(p.x, 2) + powf(p.z, 2);
	if (dist < 1)
	{
		if (p.y > o.cy.max - EPSILON
			|| is_float_equal(p.y, o.cy.max - EPSILON, EPSILON))
		{
			if (!is_float_equal(dist, 1., EPSILON))
				return (vector(0, 1, 0));
		}
		if (p.y < o.cy.min + EPSILON
			|| is_float_equal(p.y, o.cy.min + EPSILON, EPSILON))
		{
			if (!is_float_equal(dist, 1., EPSILON))
				return (vector(0, -1, 0));
		}
	}
	return (vector(p.x, 0, p.z));
}

t_vec	normal_at_co(t_object o, t_point p)
{
	float	dist;
	float	y;

	dist = powf(p.x, 2) + powf(p.z, 2);
	if (dist < 1)
	{
		if (p.y > o.cy.max - EPSILON
			|| is_float_equal(p.y, o.cy.max - EPSILON, EPSILON))
		{
			if (!is_float_equal(dist, 1., EPSILON))
				return (vector(0, 1, 0));
		}
		if (p.y < o.cy.min + EPSILON
			|| is_float_equal(p.y, o.cy.min + EPSILON, EPSILON))
		{
			if (!is_float_equal(dist, 1., EPSILON))
				return (vector(0, -1, 0));
		}
	}
	y = sqrtf(dist);
	if (p.y > 0.)
		y = -y;
	return (vector(p.x, y, p.z));
}
