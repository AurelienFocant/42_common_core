/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:02:36 by afocant           #+#    #+#             */
/*   Updated: 2024/09/28 16:30:51 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fn_check_map_file(char *map_file)
{
	size_t	len;

	len = ft_strlen(map_file);
	if (len < 5)
		fn_error_exit("Wrong map extension", EINVAL, 3);
	if (ft_strncmp(&(map_file[len - 4]), ".ber", 4) != EXIT_SUCCESS || map_file[len - 5] == '/')
		fn_error_exit("Wrong map extension", EINVAL, 4);
}

void	fn_check_nb_args(int argc)
{
	if (argc != 2)
		fn_error_exit(NULL, EINVAL, 1);
}

void	fn_check_args(int argc, char **argv)
{
	fn_check_nb_args(argc);
	fn_check_map_file(argv[1]);
}
