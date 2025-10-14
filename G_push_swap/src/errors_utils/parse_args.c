/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:31:12 by afocant           #+#    #+#             */
/*   Updated: 2024/09/09 16:35:26 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_count_args(char **av)
{
	size_t	size;

	size = 0;
	while (*av)
	{
		size++;
		av++;
	}
	return (size);
}

char	**ft_parse_str(char *str)
{
	char	**av;
	size_t	size;

	av = ft_split(str, ' ');
	if (!av)
		ft_error_exit("Error\n", 2);
	if (!*av)
		ft_free_error_exit(av, "Error\n", 3);
	size = ft_count_args(av);
	if (!ft_check_non_integers(av) || !ft_check_duplicates(av, size))
		ft_free_error_exit(av, "Error\n", 4);
	return (av);
}

char	**ft_parse_args(char **argv, size_t size)
{
	if (!ft_check_non_integers(argv) || !ft_check_duplicates(argv, size))
		ft_error_exit("Error\n", 5);
	return (argv);
}
