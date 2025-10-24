/* ************************************************************************** */
/*                                                                            */
/*   inv_utils_mat3.c                                     :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	determinant_mat2(t_mat2 m)
{
	float	det;

	det = m.mat[0][0] * m.mat[1][1] - m.mat[0][1] * m.mat[1][0];
	return (det);
}

static t_mat2	submatrix_mat3(t_mat3 m, int row, int col)
{
	int		y;
	int		x;
	int		a;
	int		b;
	t_mat2	res;

	a = 0;
	y = 0;
	while (y < 3)
	{
		if (y != row)
		{
			x = 0;
			b = 0;
			while (x < 3)
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

static float	minor_mat3(t_mat3 m, int row, int col)
{
	t_mat2	subm;

	subm = submatrix_mat3(m, row, col);
	return (determinant_mat2(subm));
}

static float	cofactor_mat3(t_mat3 m, int row, int col)
{
	if ((row + col) % 2)
		return (-minor_mat3(m, row, col));
	else
		return (minor_mat3(m, row, col));
}

float	determinant_mat3(t_mat3 m)
{
	int		i;
	float	res;

	res = 0;
	i = 0;
	while (i < 3)
	{
		res += m.mat[0][i] * cofactor_mat3(m, 0, i);
		i++;
	}
	return (res);
}
