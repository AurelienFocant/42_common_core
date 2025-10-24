/* ************************************************************************** */
/*                                                                            */
/*   tuple.c                                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_miniRT.h"
#include <stdio.h>

t_tuple	creat_tuple(float x, float y, float z, float w)
{
	t_tuple	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.w = w;
	return (p);
}

t_tuple	point(float x, float y, float z)
{
	t_tuple	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.w = POINT;
	return (p);
}

t_tuple	vector(float x, float y, float z)
{
	t_tuple	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = VECTOR;
	return (vec);
}

void	print_tuple(t_tuple t)
{
	printf("A tuple ");
	if (is_float_equal(t.w, 0, EPSILON))
		printf("vector:\n");
	else if (is_float_equal(t.w, 1, EPSILON))
		printf("point:\n");
	else
		printf("that ");
	printf("coordinate are:\nx : %f, y : %f, z : %f, w : %f\n",
		t.x, t.y, t.z, t.w);
}

t_tuple	color(float red, float green, float blue)
{
	t_tuple	c;

	c = vector(red, green, blue);
	return (c);
}
