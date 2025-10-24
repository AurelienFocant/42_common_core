/* ************************************************************************** */
/*                                                                            */
/*   2_parse_objects.c                                    :::      ::::::::   */
/*   2_parse_objects.c                                  :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/28 17:13:25 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

t_object	parse_sp(char *line)
{
	t_object	o;
	t_vec		tr;
	float		scale;

	adv_next_word(&line);
	o = create_object(SPHERE);
	tr = get_next_vector(&line);
	scale = get_next_float(&line) / 2;
	o.trans = multi_mat4(
			translation(tr.x, tr.y, tr.z), scaling(scale, scale, scale));
	o.material.color = get_next_color(&line);
	o.s.origin = point(0, 0, 0);
	o.s.radius = 1.0;
	o = parse_optionals(o, &line);
	return (o);
}

t_object	parse_pl(char *line)
{
	t_object	o;
	t_vec		tr;
	t_vec		target_normalv;
	t_mat4		rot_mat;

	adv_next_word(&line);
	o = create_object(PLANE);
	tr = get_next_vector(&line);
	target_normalv = normalize_tuple(get_next_vector(&line));
	rot_mat = rotation_matrix_Rodrigues_formula(target_normalv);
	o.trans = multi_mat4(translation(tr.x, tr.y, tr.z), rot_mat);
	o.material.color = get_next_color(&line);
	o.pl.normal = target_normalv;
	o = parse_optionals(o, &line);
	return (o);
}

t_object	parse_cu(char *line)
{
	t_object	o;
	t_vec		tr;
	t_mat4		rot_mat;
	t_vec		size;

	adv_next_word(&line);
	o = create_object(CUBE);
	tr = get_next_vector(&line);
	rot_mat = rotation_matrix_Rodrigues_formula(
			normalize_tuple(get_next_vector(&line)));
	size = get_next_vector(&line);
	o.trans = multi_mat4(multi_mat4(
		translation(tr.x, tr.y, tr.z), rot_mat), scaling(size.x, size.y, size.z));
	o.material.color = get_next_color(&line);
	o = parse_optionals(o, &line);
	return (o);
}
