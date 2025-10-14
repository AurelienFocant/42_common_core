#include "philosophers.h"

bool	fn_check_nb_of_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("wrong args\n");
		return (false);
	}
	return (true);
}

bool	fn_check_args_only_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("wrong args\n");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	fn_check_args_not_zero(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0)
		{
			printf("wrong args\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	fn_check_args(int argc, char **argv)
{
	if (!fn_check_nb_of_args(argc))
		return (false);
	if (!fn_check_args_only_digits(argv))
		return (false);
	if (!fn_check_args_not_zero(argv))
		return (false);
	return (true);
}
