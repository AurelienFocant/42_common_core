/* ************************************************************************** */
/*                                                                            */
/*   reflection_refraction.c                              :::      ::::::::   */
/*   reflection_refraction.c                            :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/22 22:22:05 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	reflected_lighting(t_world *w, t_comps *comps, int remaining_recurse)
{
	t_ray	reflect_ray;
	t_color	c;

	if (comps->obj.material.reflective == 0)
		return (color(0, 0, 0));
	if (remaining_recurse < 1)
		return (color(0, 0, 0));
	reflect_ray = ray(comps->over_point, comps->reflectv);
	c = color_at(w, reflect_ray, remaining_recurse - 1);
	return (scalar_multi_tuple(comps->obj.material.reflective, c));
}

t_ray	compute_refract_ray(float n_ratio, float cos_i, float cos_t, t_comps *comps)
{
	t_vec		direction;
	t_ray		refract_ray;

	direction = sub_tuple(
			scalar_multi_tuple(n_ratio * cos_i - cos_t, comps->normalv),
			scalar_multi_tuple(n_ratio, comps->eyev));
	refract_ray = ray(comps->under_point, direction);
	return (refract_ray);
}

t_color	refracted_lighting(t_world *w, t_comps *comps, float remaining)
{
	float		n_ratio;
	float		cos_i;
	float		sin2_t;
	float		cos_t;
	t_color		c;

	n_ratio = comps->n1 / comps->n2;
	cos_i = dot_product(comps->eyev, comps->normalv);
	sin2_t = powf(n_ratio, 2) * (1 - powf(cos_i, 2));
	if (comps->obj.material.transparency == 0 || remaining == 0
		|| sin2_t > 1)
		return (color(0, 0, 0));
	cos_t = sqrtf(1 - sin2_t);
	c = color_at(w,
			compute_refract_ray(n_ratio, cos_i,
				cos_t, comps), remaining - 1);
	c = scalar_multi_tuple(comps->obj.material.transparency, c);
	return (c);
}
