/* ************************************************************************** */
/*                                                                            */
/*   inversion.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mat4	creat_zeroed_mat4(void)
{
	t_mat4	m;
	int		y;
	int		x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			m.mat[y][x] = 0;
			x++;
		}
		y++;
	}
	return (m);
}

t_mat4	inverse_mat4(t_mat4 m)
{
	int		y;
	int		x;
	float	cofactor;
	float	determinant;
	t_mat4	res;

	determinant = determinant_mat4(m);
	if (determinant == 0)
		return (creat_zeroed_mat4());
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			cofactor = cofactor_mat4(m, y, x);
			res.mat[x][y] = cofactor / determinant;
			x++;
		}
		y++;
	}
	return (res);
}
