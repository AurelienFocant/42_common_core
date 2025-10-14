#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void print_matrix(int matrix[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(matrix[i][j] + '0');
			if (j == 3)
				ft_putchar('\n');
			else
				ft_putchar(' ');
			j++;
		}
		i++;
	}
}

void	build_empty_matrix(int matrix[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	fill_matrix(int matrix[4][4], char *str)
{
	int i;
	int x;

	i = 0;
	while (str[i])
	{
		x = i / 2;
		if (str[i] == '1')
		{
			if (x < 4)
			{
				matrix[0][x] = 4;
			}
			else if (x >= 4 && x < 8)
			{
				matrix[3][x % 4] = 4;
			}
			else if (x >= 8 && x < 12)
			{
				matrix[x % 4][0] = 4;
			}
			else if (x >= 12 && x < 16)
			{
				matrix[x % 4][3] = 4;
			}
		}
		if (str[i] == '4')
		{
			if (x < 4)
			{
				matrix[0][x] = 1;
				matrix[1][x] = 2;
				matrix[2][x] = 3;
				matrix[3][x] = 4;
			}
			else if (x >= 4 && x < 8)
			{
				matrix[3][x % 4] = 1;
				matrix[2][x % 4] = 2;
				matrix[1][x % 4] = 3;
				matrix[0][x % 4] = 4;
			}
			else if (x >= 8 && x < 12)
			{
				matrix[x % 4][0] = 1;
				matrix[x % 4][1] = 2;
				matrix[x % 4][2] = 3;
				matrix[x % 4][3] = 4;
			}
			else if (x >= 12 && x < 16)
			{
				matrix[x % 4][3] = 1;
				matrix[x % 4][2] = 2;
				matrix[x % 4][1] = 3;
				matrix[x % 4][0] = 4;
			}
		}
		i += 2;
	}
	return ;
}
