/* ************************************************************************** */
/*                                                                            */
/*   phong_model.c                                        :::      ::::::::   */
/*   phong_model.c                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/24 22:48:26 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	get_ambient(t_world *w, t_comps *comps, t_color obj_color)
{
	t_color	w_ambient;
	t_color	o_ambient;

	o_ambient = scalar_multi_tuple(comps->obj.material.ambient, obj_color);
	w_ambient = scalar_multi_tuple(w->ambient.ratio, w->ambient.color);
	return (multi_tuple(o_ambient, w_ambient));
}

void	add_specular(t_light light, t_comps *comps, t_vec lightv, t_color *sum)
{
	t_color	specular;
	t_vec	reflectv;
	float	reflect_dot_eye;
	double	factor;

	reflectv = reflect(negatif_tuple(lightv), comps->normalv);
	reflect_dot_eye = dot_product(reflectv, comps->eyev);
	if (!(reflect_dot_eye < 0. || is_float_equal(reflect_dot_eye, 0., EPSILON)))
	{
		factor = pow(reflect_dot_eye, comps->obj.material.shininess);
		specular = scalar_multi_tuple(
				comps->obj.material.specular * factor, light.color);
		specular = multi_tuple(light.brightness, specular);
		*sum = add_tuple(*sum, specular);
	}
}

void	add_diffuse(t_light light, t_comps *comps, float light_dot_normal, t_color *sum)
{
	t_color	diffuse;

	(void) light;
	diffuse = scalar_multi_tuple(
			(light_dot_normal * comps->obj.material.diffuse),
			comps->obj.material.effective_color);
	diffuse = multi_tuple(light.brightness, diffuse);
	*sum = add_tuple(*sum, diffuse);
}

void	add_diffuse_specular(t_light light, t_comps *comps, t_pair uv, t_color *sum)
{
	t_vec	lightv;
	float	light_dot_normal;

	lightv = normalize_tuple(
			sub_tuple(point_on_light(light, uv.u, uv.v), comps->over_point));
	light_dot_normal = dot_product(lightv, comps->normalv);
	if (!(light_dot_normal < 0.
			|| is_float_equal(comps->shadow_intensity, 0., EPSILON)))
	{
		add_diffuse(light, comps, light_dot_normal, sum);
		add_specular(light, comps, lightv, sum);
	}
}

t_color	color_if_pattern(t_comps *comps)
{
	if (comps->obj.material.pattern.type != EMPTY)
		return (pattern_at_object(
				&comps->obj.material.pattern, &comps->obj, comps->over_point));
	return (comps->obj.material.color);
}
