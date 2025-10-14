/* ************************************************************************** */
/*                                                                            */
/*   color_at.c                                           :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/24 23:31:42 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

t_color	intensity_per_sample(t_light *light, t_color sum, t_comps *comps)
{
	t_color	res;

	res = scalar_div_tuple(light->samples, sum);
	res = scalar_multi_tuple(comps->shadow_intensity, res);
	return (res);
}

t_color	surface_lighting(t_world *w, t_comps *comps, int which_light)
{
	t_color	ambient;
	t_color	obj_color;
	t_color	sum;
	t_pair	uv;

	obj_color = color_if_pattern(comps);
	ambient = get_ambient(w, comps, obj_color);
	comps->obj.material.effective_color = multi_tuple(
			obj_color, w->lights[which_light].color);
	sum = color(0, 0, 0);
	uv.v = 0;
	while (uv.v < w->lights[which_light].vsteps)
	{
		uv.u = 0;
		while (uv.u < w->lights[which_light].usteps)
		{
			add_diffuse_specular(w->lights[which_light], comps, uv, &sum);
			uv.u++;
		}
		uv.v++;
	}
	return (add_tuple(ambient,
			intensity_per_sample(&w->lights[which_light], sum, comps)));
}

t_color	shade_hit(t_world *w, t_comps *comps, int which_light, int remaining_recurse)
{
	float		reflectance;
	t_color		reflected_c;
	t_color		refracted_c;
	t_color		surface_c;
	t_color		c;

	w->lights[which_light].jitter_by = calc_jitter();
	comps->shadow_intensity = intensity_at(w, comps->over_point, which_light);
	surface_c = surface_lighting(w, comps, which_light);
	reflected_c = reflected_lighting(w, comps, remaining_recurse);
	refracted_c = refracted_lighting(w, comps, remaining_recurse);
	if (comps->obj.material.reflective > 0
		&& comps->obj.material.transparency > 0)
	{
		reflectance = schlick(comps);
		c = add_tuple(surface_c, scalar_multi_tuple(reflectance, reflected_c));
		c = add_tuple(c, scalar_multi_tuple((1 - reflectance), refracted_c));
		return (c);
	}
	return (add_tuple(add_tuple(surface_c, reflected_c), refracted_c));
}

t_comps	prepare_computations(t_intersection *hit, t_ray r, t_intersections *xs)
{
	t_comps	comps;

	comps.obj = *hit->obj;
	comps.t = hit->t;
	comps.point = position(r, hit->t);
	comps.eyev = negatif_tuple(r.direction);
	comps.normalv = normal_at(*hit->obj, comps.point);
	comps.inside = false;
	if (dot_product(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = negatif_tuple(comps.normalv);
	}
	comps.reflectv = reflect(r.direction, comps.normalv);
	comps.over_point = add_tuple(
			comps.point, scalar_multi_tuple(0.001, comps.normalv));
	comps.under_point = sub_tuple(
			comps.point, scalar_multi_tuple(0.001, comps.normalv));
	prepare_refractive_index(&comps, hit, xs);
	return (comps);
}

t_color	color_at(t_world *w, t_ray r, int remaining_recurse)
{
	t_intersections	*world_intersections;
	t_intersection	*first_hit;
	t_comps			comps;
	t_color			res;
	int				light;

	world_intersections = intersect_world(w, r);
	first_hit = hit(world_intersections);
	if (!first_hit)
		return (color(1, 1, 1));
	comps = prepare_computations(first_hit, r, world_intersections);
	res = color(0, 0, 0);
	light = 0;
	while (light < w->light_count && light + 1 <= w->light_count)
	{
		res = add_tuple(res, shade_hit(w, &comps, light, remaining_recurse));
		light++;
	}
	ft_free_intersections(world_intersections, false);
	return (res);
}
