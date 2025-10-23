/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:30:30 by afocant           #+#    #+#             */
/*   Updated: 2024/02/16 18:30:31 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A')
			return (0);
		else if (str[i] > 'Z' && str[i] < 'a')
			return (0);
		else if (str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}
