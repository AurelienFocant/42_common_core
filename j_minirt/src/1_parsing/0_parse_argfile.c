/* ************************************************************************** */
/*                                                                            */
/*   0_parse_argfile.c                                    :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_world	parse_argfile(char *filename)
{
	t_world	w;

	w.light_count = 0;
	w.obj_count = 0;
	check_file_and_count(filename, &w);
	parse_world(filename, &w);
	return (w);
}
