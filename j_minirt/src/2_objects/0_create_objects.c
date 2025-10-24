/* ************************************************************************** */
/*                                                                            */
/*   0_create_objects.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

t_object	create_object(t_type_obj type)
{
	t_object	o;
	static int	id = 0;

	o.type = type;
	o.trans = creat_identity_matrix();
	o.material = default_material();
	o.id = id++;
	return (o);
}
