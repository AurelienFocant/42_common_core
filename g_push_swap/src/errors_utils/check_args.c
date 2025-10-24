/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:02:17 by afocant           #+#    #+#             */
/*   Updated: 2024/09/09 16:38:59 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_str_nbr(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (FALSE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_check_non_integers(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_is_str_nbr(argv[i]))
			return (FALSE);
		if (ft_atol(argv[i]) > (long) INT_MAX)
			return (FALSE);
		if (ft_atol(argv[i]) < (long) INT_MIN)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_check_duplicates(char **argv, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

char	**ft_check_arg_errors(int argc, char **argv)
{
	char	**av;

	if (argc == 2)
		av = ft_parse_str(argv[1]);
	else
		av = ft_parse_args(argv + 1, (size_t) argc - 1);
	return (av);
}
