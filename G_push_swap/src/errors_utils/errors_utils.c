/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:39 by afocant           #+#    #+#             */
/*   Updated: 2024/09/24 12:09:11 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(char *msg, int exitcode)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(exitcode);
}

void	ft_free_null1(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_free_strv1(char **av)
{
	char	**ptr;

	ptr = av;
	while (*ptr)
	{
		ft_free_null1(*ptr);
		ptr++;
	}
	ft_free_null1(*ptr);
	free(av);
}

void	ft_free_error_exit(char **av, char *msg, int exitcode)
{
	ft_free_null_strv(&av);
	ft_error_exit(msg, exitcode);
}
