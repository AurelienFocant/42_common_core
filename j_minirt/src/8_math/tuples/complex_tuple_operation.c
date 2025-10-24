/* ************************************************************************** */
/*                                                                            */
/*   complex_tuple_operation.c                            :::      ::::::::   */
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
#include <math.h>
#include "libft.h"

float	magnitude(t_tuple vec)
{
	return (sqrtf(powf(vec.x, 2) + powf(vec.y, 2) + powf(vec.z, 2)));
}

t_tuple	normalize_tuple(t_tuple vec)
{
	t_tuple	v;
	float	m;

	m = magnitude(vec);
	v = creat_tuple((float) vec.x / m, (float) vec.y / m,
			(float) vec.z / m, (float) vec.w / m);
	return (v);
}

float	dot_product(t_tuple a, t_tuple b)
{
	float	scalar;

	scalar = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (scalar);
}

t_tuple	cross_product(t_tuple va, t_tuple vb)
{
	t_tuple	cross;
	float	x;
	float	y;
	float	z;

	x = va.y * vb.z - va.z * vb.y;
	y = va.z * vb.x - va.x * vb.z;
	z = va.x * vb.y - va.y * vb.x;
	cross = vector(x, y, z);
	return (cross);
}

t_tuple	scalar_div_tuple(float scalar, t_tuple a)
{
	return (creat_tuple(a.x / scalar, a.y / scalar,
			a.z / scalar, a.w / scalar));
}
