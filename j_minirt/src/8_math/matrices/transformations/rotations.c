/* ************************************************************************** */
/*                                                                            */
/*   rotations.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mat4	rotation_x(float rad)
{
	t_mat4	m;

	m = creat_identity_matrix();
	m.mat[1][1] = cosf(rad);
	m.mat[1][2] = -(sinf(rad));
	m.mat[2][1] = sinf(rad);
	m.mat[2][2] = cosf(rad);
	return (m);
}

t_mat4	rotation_y(float rad)
{
	t_mat4	m;

	m = creat_identity_matrix();
	m.mat[0][0] = cosf(rad);
	m.mat[0][2] = sinf(rad);
	m.mat[2][0] = -sinf(rad);
	m.mat[2][2] = cosf(rad);
	return (m);
}

t_mat4	rotation_z(float rad)
{
	t_mat4	m;

	m = creat_identity_matrix();
	m.mat[0][0] = cosf(rad);
	m.mat[0][1] = -sinf(rad);
	m.mat[1][0] = sinf(rad);
	m.mat[1][1] = cosf(rad);
	return (m);
}
