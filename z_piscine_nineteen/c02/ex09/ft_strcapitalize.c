/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:31:22 by afocant           #+#    #+#             */
/*   Updated: 2024/02/17 11:13:34 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str_tolowercase(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}
		str++;
	}
}

int	ft_isalphanum(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

int	ft_isalpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else
		return (0);
}

void	ft_toupper(char *c)
{
	*c -= 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_str_tolowercase(str);
	i = 0;
	while (str[i])
	{
		if (ft_isalphanum(str[i]))
		{
			if (ft_isalpha(str[i]))
				ft_toupper(&(str[i]));
			while (ft_isalphanum(str[i]))
				i++;
		}
		else
			i++;
	}
	return (str);
}
