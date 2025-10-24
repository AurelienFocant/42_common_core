/* ************************************************************************** */
/*                                                                            */
/*   1_rot_matrix_Rodrigues_formula.c                     :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_vec_zero(t_vec v)
{
	if (is_float_equal(v.x, 0., EPSILON)
		&& is_float_equal(v.y, 0., EPSILON)
		&& is_float_equal(v.z, 0., EPSILON))
		return (true);
	return (false);
}

t_mat4	rodrigues_formula(t_vec axis, float angle)
{
	float	c;
	float	s;
	float	t;
	t_mat4	res;

	c = cosf(angle);
	s = sinf(angle);
	t = 1 - c;
	res = creat_identity_matrix();
	res.mat[0][0] = t * powf(axis.x, 2) + c;
	res.mat[0][1] = t * axis.x * axis.y - s * axis.z;
	res.mat[0][2] = t * axis.x * axis.z + s * axis.y;
	res.mat[1][0] = t * axis.x * axis.y + s * axis.z;
	res.mat[1][1] = t * powf(axis.y, 2) + c;
	res.mat[1][2] = t * axis.y * axis.z - s * axis.x;
	res.mat[2][0] = t * axis.x * axis.z - s * axis.y;
	res.mat[2][1] = t * axis.y * axis.z + s * axis.x;
	res.mat[2][2] = t * powf(axis.z, 2) + c;
	return (res);
}

t_mat4	rotation_matrix_Rodrigues_formula(t_vec target_normalv)
{
	t_vec	axis;
	t_vec	default_normalv;
	float	angle;

	default_normalv = vector(0, 1, 0);
	axis = cross_product(default_normalv, target_normalv);
	if (is_vec_zero(axis))
	{
		if (dot_product(default_normalv, target_normalv) > 0)
			return (creat_identity_matrix());
		else
			return (rodrigues_formula(vector(1, 0, 0), M_PI));
	}
	else
	{
		angle = acosf(dot_product(default_normalv, target_normalv));
		return (rodrigues_formula(normalize_tuple(axis), angle));
	}
}
