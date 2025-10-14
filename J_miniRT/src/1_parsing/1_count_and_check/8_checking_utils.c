/* ************************************************************************** */
/*                                                                            */
/*   8_checking_utils.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	expect_float(float minmax[2], char **words, char *line, int fd)
{
	char	*s;
	float	res;

	s = *words;
	if (*s == '-')
		s++;
	if (!ft_isdigit(*s))
		file_error_exit(line, fd);
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
	{
		s++;
		while (ft_isdigit(*s))
			s++;
	}
	if (!(*s == ',' || ft_isspace(*s)))
		file_error_exit(line, fd);
	res = ft_atof(*words);
	if (res < minmax[0] || res > minmax[1])
		file_error_exit(line, fd);
	*words = s;
	return (res);
}

void	expect_single_float(float minmax[2], char **words, char *line, int fd)
{
	expect_float(minmax, words, line, fd);
	expect_whitespace(words, line, fd);
}

void	expect_vector(float minmax[2], char **words, char *line, int fd)
{
	expect_float(minmax, words, line, fd);
	expect_comma(words, line, fd);
	expect_float(minmax, words, line, fd);
	expect_comma(words, line, fd);
	expect_float(minmax, words, line, fd);
	expect_whitespace(words, line, fd);
}

void	expect_whitespace(char **words, char *line, int fd)
{
	if (!ft_isspace(**words))
		file_error_exit(line, fd);
	while (ft_isspace(**words))
		(*words)++;
}

void	expect_comma(char **words, char *line, int fd)
{
	if (**words != ',')
		file_error_exit(line, fd);
	(*words)++;
}
