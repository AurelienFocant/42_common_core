/* ************************************************************************** */
/*                                                                            */
/*   matrices.c                                           :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mat4	multi_mat4(t_mat4 m1, t_mat4 m2)
{
	int		y;
	int		x;
	int		i;
	t_mat4	res;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			res.mat[y][x] = 0;
			i = 0;
			while (i < 4)
			{
				res.mat[y][x] += m1.mat[y][i] * m2.mat[i][x];
				if (is_float_equal(res.mat[y][x], 0, EPSILON))
					res.mat[y][x] = 0.;
				i++;
			}
			x++;
		}
		y++;
	}
	return (res);
}

static float	dot_mat(float a[4], t_tuple b)
{
	return (a[0] * b.x + a[1] * b.y + a[2] * b.z + a[3] * b.w);
}

t_tuple	multi_mat4_tuple(t_mat4 m, t_tuple t)
{
	t_tuple	res;

	res.x = dot_mat(m.mat[0], t);
	res.y = dot_mat(m.mat[1], t);
	res.z = dot_mat(m.mat[2], t);
	res.w = dot_mat(m.mat[3], t);
	return (res);
}

t_mat4	creat_identity_matrix(void)
{
	int		x;
	int		y;
	t_mat4	m;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (y == x)
				m.mat[y][x] = 1;
			else
				m.mat[y][x] = 0;
			x++;
		}
		y++;
	}
	return (m);
}

t_mat4	transpose_mat4(t_mat4 m)
{
	int		x;
	int		y;
	t_mat4	res;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			res.mat[y][x] = m.mat[x][y];
			x++;
		}
		y++;
	}
	return (res);
}
