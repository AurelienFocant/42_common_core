/* ************************************************************************** */
/*                                                                            */
/*   operation_tuple.c                                    :::      ::::::::   */
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

t_tuple	add_tuple(t_tuple a, t_tuple b)
{
	return (creat_tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

t_tuple	sub_tuple(t_tuple a, t_tuple b)
{
	return (creat_tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
}

t_tuple	negatif_tuple(t_tuple a)
{
	return (sub_tuple(vector(0.0, 0.0, 0.0), a));
}

t_tuple	multi_tuple(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t.x = a.x * b.x;
	t.y = a.y * b.y;
	t.z = a.z * b.z;
	t.w = a.w * b.w;
	return (t);
}

t_tuple	scalar_multi_tuple(float scalar, t_tuple a)
{
	return (creat_tuple(a.x * scalar, a.y * scalar,
			a.z * scalar, a.w * scalar));
}
