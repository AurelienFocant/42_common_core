/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:09:00 by afocant           #+#    #+#             */
/*   Updated: 2024/02/28 22:16:12 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_toa);
char	*ft_itoa_base(int n, char *base);

int	main(void)
{
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "01234567"));
}
