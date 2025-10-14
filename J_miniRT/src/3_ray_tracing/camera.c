/* ************************************************************************** */
/*                                                                            */
/*   camera.c                                             :::      ::::::::   */
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

t_camera	camera(float hsize, float vsize, float field_of_view)
{
	t_camera	c;
	float		half_view;
	float		aspect_ratio;

	c.hsize = hsize;
	c.vsize = vsize;
	c.field_of_view = field_of_view;
	c.transform = creat_identity_matrix();
	half_view = tan(field_of_view / 2.);
	aspect_ratio = hsize / vsize;
	if (aspect_ratio >= 1 || is_float_equal(aspect_ratio, 1., EPSILON))
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect_ratio;
	}
	else
	{
		c.half_width = half_view * aspect_ratio;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	return (c);
}

float	calc_world_pixel(int point, float pixel_size, float border)
{
	float	world_pixel;
	float	offset;

	offset = ((float) point + 0.5) * pixel_size;
	world_pixel = border - offset;
	if (is_float_equal(world_pixel, 0., EPSILON))
		world_pixel = 0.;
	return (world_pixel);
}

t_ray	ray_to_world_pixel(t_camera c, int x, int y)
{
	float	world_x;
	float	world_y;
	t_point	pixel;
	t_point	origin;
	t_point	direction;

	world_x = calc_world_pixel(x, c.pixel_size, c.half_width);
	world_y = calc_world_pixel(y, c.pixel_size, c.half_height);
	pixel = multi_mat4_tuple(
			inverse_mat4(c.transform), point(world_x, world_y, -1));
	origin = multi_mat4_tuple(
			inverse_mat4(c.transform), point(0, 0, 0));
	direction = normalize_tuple(sub_tuple(pixel, origin));
	return (ray(origin, direction));
}

int	vec_to_hex_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (int)round(fmaxf(0.0f, fminf(1.0f, color.x)) * 255.0f);
	g = (int)round(fmaxf(0.0f, fminf(1.0f, color.y)) * 255.0f);
	b = (int)round(fmaxf(0.0f, fminf(1.0f, color.z)) * 255.0f);
	return (r << 16 | g << 8 | b);
}
