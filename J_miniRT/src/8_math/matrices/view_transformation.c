/* ************************************************************************** */
/*                                                                            */
/*   view_transformation.c                                :::      ::::::::   */
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

t_mat4	view_transform(t_point from, t_point to, t_vec up)
{
	t_vec	forward;
	t_vec	upn;
	t_vec	left;
	t_vec	true_up;
	t_mat4	m;

	forward = normalize_tuple(sub_tuple(to, from));
	upn = normalize_tuple(up);
	left = cross_product(forward, upn);
	true_up = cross_product(left, forward);
	m = creat_identity_matrix();
	m.mat[0][0] = left.x;
	m.mat[0][1] = left.y;
	m.mat[0][2] = left.z;
	m.mat[1][0] = true_up.x;
	m.mat[1][1] = true_up.y;
	m.mat[1][2] = true_up.z;
	m.mat[2][0] = -forward.x;
	m.mat[2][1] = -forward.y;
	m.mat[2][2] = -forward.z;
	m = multi_mat4(m, translation((float) -from.x,
				(float) -from.y, (float) -from.z));
	return (m);
}
