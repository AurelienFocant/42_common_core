/* ************************************************************************** */
/*                                                                            */
/*   0_material.c                                         :::      ::::::::   */
/*   0_material.c                                       :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/24 20:41:30 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_pattern	empty_pattern(void)
{
	t_pattern	p;

	p.type = EMPTY;
	p.trans = creat_identity_matrix();
	return (p);
}

t_material	default_material(void)
{
	t_material	m;

	m.color = color(1, 1, 1);
	m.ambient = 0.2;
	m.diffuse = 0.9;
	m.specular = 0.2;
	m.shininess = 200;
	m.reflective = 0.;
	m.transparency = 0.;
	m.refractive_index = 1;
	m.pattern = empty_pattern();
	return (m);
}
