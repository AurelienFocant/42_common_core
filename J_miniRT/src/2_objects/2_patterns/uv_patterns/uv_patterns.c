/* ************************************************************************** */
/*                                                                            */
/*   uv_patterns.c                                        :::      ::::::::   */
/*   uv_patterns.c                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/24 21:56:43 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	cube_colors(t_uv_pattern *ck, float u, float v)
{
	if (v > 0.8)
	{
		if (u < 0.2)
			return (ck->cube_face.c.ul);
		if (u > 0.8)
			return (ck->cube_face.c.ur);
	}
	else if (v < 0.2)
	{
		if (u < 0.2)
			return (ck->cube_face.c.bl);
		if (u > 0.8)
			return (ck->cube_face.c.br);
	}
	return (ck->cube_face.c.main);
}

t_color	cube_textures(t_uv_pattern *ck, float u, float v)
{
	float	u2;
	float	v2;
	int		face;

	v = 1.0f - v;
	face = ck->cube_face.face;
	u2 = u * (ck->cube_face.tex[face].width - 1);
	v2 = v * (ck->cube_face.tex[face].width - 1);
	return (get_pixel(&ck->cube_face.tex[face], roundf(u2), roundf(v2)));
}

t_color	mapped_checkers(t_uv_pattern *uv_pat, float u, float v)
{
	float	u2;
	float	v2;
	int		res;

	u2 = floorf(u * uv_pat->checkers.width);
	v2 = floorf(v * uv_pat->checkers.height);
	res = (int)(u2 + v2) % 2;
	if (res == 0)
		return (uv_pat->checkers.c1);
	return (uv_pat->checkers.c2);
}

t_color	texture(t_uv_pattern *uv_pat, float u, float v)
{
	float	u2;
	float	v2;

	v = 1.0f - v;
	u2 = u * uv_pat->tex->width;
	v2 = v * uv_pat->tex->height;
	return (get_pixel(uv_pat->tex, roundf(u2), roundf(v2)));
}

t_color	uv_pattern_at(t_uv_pattern *uv_pat, float u, float v)
{
	if (uv_pat->uv_type == MAPPED_CHECKERS)
		return (mapped_checkers(uv_pat, u, v));
	else if (uv_pat->uv_type == TEXTURE)
		return (texture(uv_pat, u, v));
	else if (uv_pat->uv_type == CUBE_TEXTURES)
		return (cube_textures(uv_pat, u, v));
	else if (uv_pat->uv_type == CUBE_COLORS)
		return (cube_colors(uv_pat, u, v));
	return (color(0, 0, 0));
}
