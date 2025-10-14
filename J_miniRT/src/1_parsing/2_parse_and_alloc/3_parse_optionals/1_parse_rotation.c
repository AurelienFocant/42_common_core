#include "miniRT.h"
#include "prototypes_miniRT.h"

int	which_axes(char **line)
{
	if (**line == 'x')
		return (0);
	if (**line == 'y')
		return (1);
	if (**line == 'z')
		return (2);
	return (-1);
}

t_mat4	find_and_do_rotation(int which, float radians)
{
	t_mat4	res;

	res = creat_identity_matrix();
	if (which == 0)
		res = rotation_x(radians);
	else if (which == 1)
		res = rotation_y(radians);
	else
	 res = rotation_z(radians);
	return (res);
}

void	parse_rotation(t_object *o, char **line)
{
	int			which;
	float		radians;
	t_mat4	rotated;

	adv_next_word(line);
	consume_paren(line);
	which = which_axes(line);
	if (which == -1)
		return ;
	adv_next_word(line);
	radians = get_next_float(line) * (M_PI / 180.);
	rotated = find_and_do_rotation(which, radians);
	o->trans = multi_mat4(rotated, o->trans);
}
