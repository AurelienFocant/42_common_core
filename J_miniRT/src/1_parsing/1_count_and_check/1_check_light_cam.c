/* ************************************************************************** */
/*                                                                            */
/*   1_check_light_cam.c                                  :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_light(char *line, int fd)
{
	char	*words;

	words = line;
	adv_next_word(&words);
	expect_vector((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_single_float((float []){0, 1}, &words, line, fd);
	expect_vector((float []){0, 255}, &words, line, fd);
	return (1);
}

void	check_camera(char *line, int fd)
{
	char	*words;

	words = line;
	adv_next_word(&words);
	expect_vector((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_vector((float []){-1, 1}, &words, line, fd);
	expect_single_float((float []){0, 180}, &words, line, fd);
	expect_end(&words, line, fd);
}

void	check_ambient(char *line, int fd)
{
	char	*words;

	words = line;
	adv_next_word(&words);
	expect_single_float((float []){0, 1}, &words, line, fd);
	expect_vector((float []){0, 255}, &words, line, fd);
	expect_end(&words, line, fd);
}
