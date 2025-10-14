#include "libft.h"

int	ft_is_a_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

int	parse_sign(char **s)
{
	char	*str;
	int		neg_flag;

	str = *s;
	neg_flag = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg_flag = -1;
		str++;
	}
	*s = str;
	return (neg_flag);
}

double	ft_atof(char *str)
{
	double	n;
	double	fraction;
	int		neg_flag;
	int		divider;

	while (ft_is_a_space(*str))
		str++;
	neg_flag = parse_sign(&str);
	n = 0;
	while (ft_isdigit(*str))
		n = (n * 10) + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		fraction = 0.0;
		divider = 1;
		while (ft_isdigit(*str))
		{
			fraction = (fraction * 10) + (*str++ - '0');
			divider *= 10;
		}
		n += fraction / divider;
	}
	return (n * neg_flag);
}
