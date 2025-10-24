/* ************************************************************************** */
/*                                                                            */
/*   3_parse_textures.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:39:13 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

size_t	len_tex(char *line)
{
	size_t	len;

	len = 0;
	while (line[len])
	{
		if (line[len] == ',' || line[len] == ')')
			break ;
		len++;
	}
	return (len);
}

char	*get_next_filename(char **line)
{
	size_t	len;
	char	*res;

	len = len_tex(*line);
	res = ft_substr(*line, 0, len);
	if (!res)
		return (NULL);
	return (res);
}

char	*get_texture_path(char **line)
{
	char	*filename;
	char	*file;

	filename = get_next_filename(line);
	if (!filename)
	{
		ft_dprintf(STDERR_FILENO, "Wrong texture file\n");
		return (NULL);
	}
	file = ft_cat_strs(3, "./texture_files/", filename, ".xpm");
	free(filename);
	if (!file)
	{
		ft_dprintf(STDERR_FILENO, "Wrong texture file\n");
		return (NULL);
	}
	adv_next_word(line);
	return (file);
}

char	*get_cube_textures_dir(char **line)
{
	char	*filename;
	char	*file;

	filename = get_next_filename(line);
	if (!filename)
	{
		ft_dprintf(STDERR_FILENO, "Wrong texture file\n");
		return (NULL);
	}
	file = ft_cat_strs(3, "./texture_files/cube/", filename, "/");
	free(filename);
	if (!file)
	{
		ft_dprintf(STDERR_FILENO, "Wrong texture file\n");
		return (NULL);
	}
	adv_next_word(line);
	return (file);
}

void	parse_texture(t_object *o, char **line)
{
	adv_next_word(line);
	consume_paren(line);
	if (o->type == CUBE)
	{
		o->material.pattern.uv_pat.texture_path = get_cube_textures_dir(line);
		if (o->material.pattern.uv_pat.texture_path)
		{
			o->material.pattern.type = UV_PAT;
			o->material.pattern.uv_pat.uv_type = CUBE_TEXTURES;
		}
		else
			o->material.pattern.type = SIMPLE;
	}
	else
	{
		o->material.pattern.uv_pat.texture_path = get_texture_path(line);
		if (o->material.pattern.uv_pat.texture_path)
		{
			o->material.pattern.type = UV_PAT;
			o->material.pattern.uv_pat.uv_type = TEXTURE;
		}
		else
			o->material.pattern.type = SIMPLE;
	}
}
