/* ************************************************************************** */
/*                                                                            */
/*   free.c                                               :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/17 18:41:57 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_free_tex_face(t_texture *tex, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, tex[0].img);
	mlx_destroy_image(mlx->mlx, tex[1].img);
	mlx_destroy_image(mlx->mlx, tex[2].img);
	mlx_destroy_image(mlx->mlx, tex[3].img);
	mlx_destroy_image(mlx->mlx, tex[4].img);
	mlx_destroy_image(mlx->mlx, tex[5].img);
	free(tex);
}

void	ft_free_tex_world(t_world *w, t_mlx *mlx)
{
	int			i;
	t_object	*obj;

	i = -1;
	while (++i < w->obj_count)
	{
		obj = &w->obj[i];
		if (obj->material.pattern.type == UV_PAT)
		{
			if (obj->material.pattern.uv_pat.uv_type == TEXTURE)
			{
				mlx_destroy_image(mlx->mlx,
					obj->material.pattern.uv_pat.tex->img);
				free(obj->material.pattern.uv_pat.tex);
				free(obj->material.pattern.uv_pat.texture_path);
			}
			if (obj->material.pattern.uv_pat.uv_type == CUBE_TEXTURES)
			{
				ft_free_tex_face(obj->material.pattern.uv_pat.cube_face.tex,
					mlx);
				free(obj->material.pattern.uv_pat.texture_path);
			}
		}
	}
}

void	ft_free_intersections(t_intersections *xs, bool is_containers)
{
	t_intersections	*tmp;

	if (!xs)
		return ;
	tmp = xs->next;
	while (xs)
	{
		if (is_containers == false)
			free(xs->hit);
		free(xs);
		xs = tmp;
		if (!xs)
			break ;
		tmp = xs->next;
	}
}
