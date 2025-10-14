/* ************************************************************************** */
/*                                                                            */
/*   glass1_material.c                                    :::      ::::::::   */
/*   glass1_material.c                                  :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/20 19:07:14 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	glass1_object(t_object *o)
{
	o->material.transparency = 0.9;
	o->material.refractive_index = 2.7;

	o->material.reflective = 0;
	// o->material.diffuse /= 2;
	// o->material.ambient /=2;
}

void	glass2_object(t_object *o)
{
	o->material.specular = 0.6;
	o->material.shininess = 20;
	o->material.reflective = 0.6;
	o->material.ambient = 0;
	o->material.diffuse = 0.4;
}

void	glass3_object(t_object *o)
{
	o->material.diffuse = 0.6;
	o->material.ambient = 0.1;
	o->material.specular = 0.;
	o->material.reflective = 0.2;
	o->material.shininess = 0;
	o->material.refractive_index = 0;
}
