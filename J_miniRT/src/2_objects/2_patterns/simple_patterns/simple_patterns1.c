/* ************************************************************************** */
/*                                                                            */
/*   simple_patterns1.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	checker_at(t_simple_pattern *pat, t_point p)
{
	int	x;
	int	y;
	int	z;

	x = (int) floorf(p.x);
	y = (int) floorf(p.y);
	z = (int) floorf(p.z);
	if ((int)(x + y + z) % 2 == 0)
		return (pat->c1);
	return (pat->c2);
}

t_color	texture_map(t_uv_pattern *pat, t_object *o, t_point p)
{
	t_pair	pair;

	if (o->type == SPHERE)
		pair = spherical_map(p);
	else if (o->type == PLANE)
		pair = planar_map(p);
	else if (o->type == CYLINDER)
		pair = cylindrical_map(p);
	else if (o->type == CUBE)
	{
		pat->cube_face.face = face_form_point(p);
		pair = cube_map(p, pat->cube_face.face);
	}
	return (uv_pattern_at(pat, pair.u, pair.v));
}

t_color	simple_pat(t_simple_pattern *pat, t_point pattern_space)
{
	if (pat->simp_type == GRADIENT)
		return (gradient_at(pat, pattern_space));
	else if (pat->simp_type == STRIPE)
		return (stripe_at(pat, pattern_space));
	else if (pat->simp_type == RING)
		return (ring_at(pat, pattern_space));
	else if (pat->simp_type == CHECKER)
		return (checker_at(pat, pattern_space));
	return (color(0, 0, 0));
}
