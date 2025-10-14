/* ************************************************************************** */
/*                                                                            */
/*   transformations.c                                    :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mat4	translation(float x, float y, float z)
{
	t_mat4	res;

	res = creat_identity_matrix();
	res.mat[0][3] = x;
	res.mat[1][3] = y;
	res.mat[2][3] = z;
	res.mat[3][3] = 1;
	return (res);
}

t_mat4	scaling(float x, float y, float z)
{
	t_mat4	res;

	res = creat_identity_matrix();
	res.mat[0][0] = x;
	res.mat[1][1] = y;
	res.mat[2][2] = z;
	res.mat[3][3] = 1;
	return (res);
}

t_mat4	shearing(float sh[6])
{
	t_mat4	m;

	m = creat_identity_matrix();
	m.mat[0][1] = sh[XY];
	m.mat[0][2] = sh[XZ];
	m.mat[1][0] = sh[YX];
	m.mat[1][2] = sh[YZ];
	m.mat[2][0] = sh[ZX];
	m.mat[2][1] = sh[ZY];
	return (m);
}
