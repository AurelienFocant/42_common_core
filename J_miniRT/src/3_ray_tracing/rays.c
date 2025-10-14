/* ************************************************************************** */
/*                                                                            */
/*   rays.c                                               :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

t_ray	ray(t_point origin, t_vec direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_point	position(t_ray ray, float t)
{
	return (add_tuple(ray.origin, scalar_multi_tuple(t, ray.direction)));
}

t_ray	transform_r(t_ray r, t_mat4 m)
{
	t_ray	r2;

	r2.origin = (multi_mat4_tuple(m, r.origin));
	r2.direction = (multi_mat4_tuple(m, r.direction));
	return (r2);
}

t_vec	reflect(t_vec in, t_vec normal)
{
	return (sub_tuple(in, scalar_multi_tuple(dot_product(in, normal),
				scalar_multi_tuple(2.0, normal))));
}
