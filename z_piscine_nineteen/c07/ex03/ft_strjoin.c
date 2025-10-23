/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:24:55 by afocant           #+#    #+#             */
/*   Updated: 2024/02/29 17:47:27 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += (size - 1) * ft_strlen(sep);
	return (len);
}

void	fill_nul(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		total_len;
	int		i;

	if (size == 0)
		total_len = 0;
	else
		total_len = get_total_len(size, strs, sep);
	joined = malloc(sizeof(char) * (total_len + 1));
	if (joined == NULL)
		return (NULL);
	fill_nul(joined, total_len + 1);
	i = 0;
	while (i < size)
	{
		ft_strcat(joined, strs[i]);
		if (i < size - 1)
			ft_strcat(joined, sep);
		i++;
	}
	joined[total_len] = '\0';
	return (joined);
}


#include <stdio.h>
int main(int ac, char **argv)
{
	char **strs;
	printf("%s\n", ft_strjoin(0, strs, " "));
}
