/* ************************************************************************** */
/*                                                                            */
/*   options.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:27:19 by afocant           #+#    #+#             */
/*   Updated: 2025/03/19 18:27:31 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

int	count_dashes(char *arg)
{
	int	n;

	n = 0;
	while (*arg && *arg == '-')
	{
		n++;
		arg++;
	}
	return (n);
}

char	*get_first_non_option(char **arg)
{
	while (*arg)
	{
		if ((*arg)[0] != '-')
			return (*arg);
		if (count_dashes(*arg) > 2)
			return (*arg);
		arg++;
	}
	return (NULL);
}
