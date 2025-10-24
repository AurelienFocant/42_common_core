/* ************************************************************************** */
/*                                                                            */
/*   9_checking_utils2.c                                  :::      ::::::::   */
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

void	expect_bool(char **words, char *line, int fd)
{
	float	f;

	f = expect_float((float []){0, 1}, words, line, fd);
	if (!(f == 0 || f == 1))
		file_error_exit(line, fd);
	expect_whitespace(words, line, fd);
}

void	expect_end(char **words, char *line, int fd)
{
	if (**words != '\0')
		file_error_exit(line, fd);
}

bool	is_just_whitespace(char *line)
{
	char	*words;

	words = line;
	while (ft_isspace(*words))
		words++;
	if (*words != '\0')
		return (false);
	return (true);
}
