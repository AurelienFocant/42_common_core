/* ************************************************************************** */
/*                                                                            */
/*   1_parse_patterns.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:38:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_pattern_type(t_object *o, char **line)
{
	if (**line == 'S' || **line == 'G' || **line == 'R'
		|| (**line == 'C' && *(*line + 1) == 'H'))
	{
		o->material.pattern.type = SIMPLE;
		// dont hardcode this -->
		o->material.pattern.trans = scaling(0.5, 0.5, 0.5);
		if (**line == 'S')
			o->material.pattern.simp_pat.simp_type = STRIPE;
		else if (**line == 'G')
			o->material.pattern.simp_pat.simp_type = GRADIENT;
		else if (**line == 'R')
			o->material.pattern.simp_pat.simp_type = RING;
		else if (**line == 'C')
			o->material.pattern.simp_pat.simp_type = CHECKER;
	}
	else
	{
		o->material.pattern.type = UV_PAT;
		if (**line == 'M')
			o->material.pattern.uv_pat.uv_type = MAPPED_CHECKERS;
		else if (**line == 'C')
			o->material.pattern.uv_pat.uv_type = CUBE_COLORS;
	}
}

void	parse_simple_pattern(t_object *o, char **line)
{
	o->material.pattern.simp_pat.c1 = o->material.color;
	o->material.pattern.simp_pat.c2 = get_next_color(line);
}

void	parse_uv_pattern(t_object *o, char **line)
{
	if (o->material.pattern.uv_pat.uv_type == MAPPED_CHECKERS)
	{
		o->material.pattern.uv_pat.checkers.c1 = o->material.color;
		o->material.pattern.uv_pat.checkers.c2 = get_next_color(line);
		o->material.pattern.uv_pat.checkers.width = 16;
		o->material.pattern.uv_pat.checkers.height = 8;
	}
	else if (o->material.pattern.uv_pat.uv_type == CUBE_COLORS)
	{
		o->material.pattern.uv_pat.cube_face.c.main = o->material.color;
		o->material.pattern.uv_pat.cube_face.c.ul = get_next_color(line);
		o->material.pattern.uv_pat.cube_face.c.ur = get_next_color(line);
		o->material.pattern.uv_pat.cube_face.c.bl = get_next_color(line);
		o->material.pattern.uv_pat.cube_face.c.br = get_next_color(line);
	}
}

void	parse_pattern(t_object *o, char **line)
{
	adv_next_word(line);
	consume_paren(line);
	get_pattern_type(o, line);
	if (o->material.pattern.type == SIMPLE)
		parse_simple_pattern(o, line);
	else
		parse_uv_pattern(o, line);
}
