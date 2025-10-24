/* ************************************************************************** */
/*                                                                            */
/*   3_parse_obj_cy_co.c                                  :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	parse_cy(char *line)
{
	t_object	o;
	t_vec		tr;
	t_mat4		rot_mat;
	float		scale;
	float		size;

	adv_next_word(&line);
	o = create_object(CYLINDER);
	tr = get_next_vector(&line);
	rot_mat = rotation_matrix_Rodrigues_formula(
			normalize_tuple(get_next_vector(&line)));
	scale = get_next_float(&line) / 2;
	size = get_next_float(&line);
	o.trans = multi_mat4(multi_mat4(
				translation(tr.x, tr.y, tr.z),
				rot_mat), scaling(scale, 1, scale));
	o.material.color = get_next_color(&line);
	o.cy.min = -(size / 2.);
	o.cy.max = size / 2.;
	o.cy.closed = true;
	o = parse_optionals(o, &line);
	return (o);
}

t_object	parse_co(char *line)
{
	t_object	o;
	t_vec		tr;
	t_mat4		rot_mat;
	float		scale;
	float		size;

	adv_next_word(&line);
	o = create_object(CONE);
	tr = get_next_vector(&line);
	rot_mat = rotation_matrix_Rodrigues_formula(
			normalize_tuple(get_next_vector(&line)));
	scale = get_next_float(&line) / 2;
	size = get_next_float(&line);
	o.co.trunc = true;
	o.co.min = -(size / 2.);
	o.co.max = size / 2.;
	o.co.max = o.co.max - (o.co.max - o.co.min) / 2;
	o.trans = translation(0, (o.co.max - o.co.min) / 2, 0);
	o.trans = multi_mat4(multi_mat4(multi_mat4(
					o.trans, translation(tr.x, tr.y, tr.z)),
				rot_mat), scaling(scale, 1, scale));
	o.material.color = get_next_color(&line);
	o.co.closed = true;
	o = parse_optionals(o, &line);
	return (o);
}
