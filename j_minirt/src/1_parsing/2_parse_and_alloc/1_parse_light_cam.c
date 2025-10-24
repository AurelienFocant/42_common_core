/* ************************************************************************** */
/*                                                                            */
/*   1_parse_light_cam.c                                  :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

void	area_light(t_light *light, t_vec v1, t_vec v2, t_pair uv)
{
	light->uvec = scalar_div_tuple(uv.u, v1);
	light->vvec = scalar_div_tuple(uv.v, v2);
	light->usteps = uv.u;
	light->vsteps = uv.v;
	light->samples = uv.u * uv.v;
	light->corner = light->position;
}

t_light	build_spot_light(t_light l, char **line)
{
	float	f;
	t_pair	uv;

	f = 0;
	if (**line && **line != '\n')
	{
		if (ft_isdigit(**line))
			f = get_next_float(line);
	}
	if (!f)
		f = 1;
	if (f == 10)
	{
		uv.u = 10;
		uv.v = 5;
		area_light(&l, vector(10, 0, 0), vector(0, 5, 0), uv);
		return (l);
	}
	uv.u = f;
	uv.v = f;
	area_light(&l, vector(1, 0, 0), vector(0, 0, 1), uv);
	return (l);
}

t_light	parse_light(char *line)
{
	t_light	l;
	double	brightness;

	adv_next_word(&line);
	l.position = get_next_vector(&line);
	l.position.w = POINT;
	brightness = get_next_float(&line);
	l.brightness = vector(brightness, brightness, brightness);
	l.color = scalar_multi_tuple(brightness, get_next_color(&line));
	l = build_spot_light(l, &line);
	return (l);
}

t_ambient	parse_ambient(char *line)
{
	t_ambient	a;

	adv_next_word(&line);
	a.ratio = get_next_float(&line);
	a.color = get_next_color(&line);
	return (a);
}

t_camera	parse_camera(char *line)
{
	t_camera	c;
	t_point		position;
	t_point		looked_at;
	t_vec		orientation;
	float		field_of_view_in_degrees;

	adv_next_word(&line);
	position = get_next_vector(&line);
	position.w = POINT;
	orientation = normalize_tuple(get_next_vector(&line));
	orientation.w = VECTOR;
	field_of_view_in_degrees = get_next_float(&line);
	c = camera(WIDTH, HEIGHT, field_of_view_in_degrees * M_PI / 180);
	looked_at = add_tuple(position, orientation);
	c.transform = view_transform(position, looked_at, vector(0, 1, 0));
	return (c);
}
