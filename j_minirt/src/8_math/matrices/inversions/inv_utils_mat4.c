/* ************************************************************************** */
/*                                                                            */
/*   inv_utils_mat4.c                                     :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_mat3	submatrix_mat4(t_mat4 m, int row, int col)
{
	int		y;
	int		x;
	int		a;
	int		b;
	t_mat3	res;

	a = 0;
	y = 0;
	while (y < 4)
	{
		if (y != row)
		{
			x = 0;
			b = 0;
			while (x < 4)
			{
				if (x != col)
					res.mat[a][b++] = m.mat[y][x];
				x++;
			}
			a++;
		}
		y++;
	}
	return (res);
}

static float	minor_mat4(t_mat4 m, int row, int col)
{
	t_mat3	subm;
	float	minor;

	subm = submatrix_mat4(m, row, col);
	minor = determinant_mat3(subm);
	return (minor);
}

float	cofactor_mat4(t_mat4 m, int row, int col)
{
	if ((row + col) % 2)
		return (-minor_mat4(m, row, col));
	else
		return (minor_mat4(m, row, col));
}

float	determinant_mat4(t_mat4 m)
{
	int		i;
	float	res;

	res = 0;
	i = 0;
	while (i < 4)
	{
		res += m.mat[0][i] * cofactor_mat4(m, 0, i);
		i++;
	}
	return (res);
}
