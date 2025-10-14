/* ************************************************************************** */
/*                                                                            */
/*   2_check_objects.c                                    :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_sp(char *line, int fd)
{
	char	*words;

	words = line;
	adv_next_word(&words);
	expect_vector((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_single_float((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_vector((float []){0, 255}, &words, line, fd);
	return (1);
}

int	check_pl(char *line, int fd)
{
	char	*words;

	words = line;
	adv_next_word(&words);
	expect_vector((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_vector((float []){-1, 1}, &words, line, fd);
	expect_vector((float []){0, 255}, &words, line, fd);
	return (1);
}

int	check_cy(char *line, int fd)
{
	char	*words;

	words = line;
	adv_next_word(&words);
	expect_vector((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_vector((float []){-1, 1}, &words, line, fd);
	expect_single_float((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_single_float((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_vector((float []){0, 255}, &words, line, fd);
	return (1);
}

int	check_co(char *line, int fd)
{
	char	*words;

	words = line;
	adv_next_word(&words);
	expect_vector((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_vector((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_single_float((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_single_float((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_vector((float []){0, 255}, &words, line, fd);
	return (1);
}

int	check_cu(char *line, int fd)
{
	char	*words;

	words = line;
	adv_next_word(&words);
	expect_vector((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_vector((float []){-1, 1}, &words, line, fd);
	expect_vector((float []){-INFINITY, INFINITY}, &words, line, fd);
	expect_vector((float []){0, 255}, &words, line, fd);
	return (1);
}
