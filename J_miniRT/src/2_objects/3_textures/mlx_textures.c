/* ************************************************************************** */
/*                                                                            */
/*   mlx_textures.c                                       :::      ::::::::   */
/*   mlx_textures.c                                     :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/24 17:58:15 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	create_tex(t_mlx *mlx, char *path, t_texture *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx,
			path, &tex->width, &tex->height);
	if (!tex->img)
		return (false);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->size_line, &tex->endian);
	if (!tex->addr)
		return (false);
	return (true);
}

char	*create_cube_texture_path(t_object *o, int f)
{
	char	*path;

	path = NULL;
	if (f == LEFT)
		path = ft_strjoin(o->material.pattern.uv_pat.texture_path, "negx.xpm");
	else if (f == RIGHT)
		path = ft_strjoin(o->material.pattern.uv_pat.texture_path, "posx.xpm");
	else if (f == UP)
		path = ft_strjoin(o->material.pattern.uv_pat.texture_path, "posy.xpm");
	else if (f == DOWN)
		path = ft_strjoin(o->material.pattern.uv_pat.texture_path, "negy.xpm");
	else if (f == FRONT)
		path = ft_strjoin(o->material.pattern.uv_pat.texture_path, "posz.xpm");
	else if (f == BACK)
		path = ft_strjoin(o->material.pattern.uv_pat.texture_path, "negz.xpm");
	if (!path)
		failed_texture_msg(o);
	return (path);
}

void	activate_simple_texture(t_object *o, t_mlx *mlx)
{
	o->material.pattern.uv_pat.tex = malloc(sizeof(t_texture));
	if (!o->material.pattern.uv_pat.tex)
		failed_texture_msg(o);
	if (!create_tex(mlx, o->material.pattern.uv_pat.texture_path, o->material.pattern.uv_pat.tex))
	{
		free(o->material.pattern.uv_pat.tex);
		failed_texture_msg(o);
	}
}

void	activate_cube_texture(t_object *o, t_mlx *mlx)
{
	char	*path;
	int		f;

	o->material.pattern.uv_pat.cube_face.tex = malloc(sizeof(t_texture) * 6);
	if (!o->material.pattern.uv_pat.cube_face.tex)
		failed_texture_msg(o);
	f = 0;
	while (f < 6)
	{
		path = create_cube_texture_path(o, f);
		if (!create_tex(mlx, path, (o->material.pattern.uv_pat.cube_face.tex + f)))
		{
			free(o->material.pattern.uv_pat.cube_face.tex);
			failed_texture_msg(o);
			break ;
		}
		free(path);
		f++;
	}
}

void	activate_textures(t_world *w, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < w->obj_count)
	{
		if (w->obj[i].material.pattern.type == UV_PAT)
		{
			if (w->obj[i].material.pattern.uv_pat.uv_type == TEXTURE)
				activate_simple_texture(&(w->obj[i]), mlx);
			else if (w->obj[i].material.pattern.uv_pat.uv_type == CUBE_TEXTURES)
				activate_cube_texture(&(w->obj[i]), mlx);
		}
		i++;
	}
}
