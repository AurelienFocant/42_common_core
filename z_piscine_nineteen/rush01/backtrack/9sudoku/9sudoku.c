#include <stdio.h>

void print_sudoku(int sudoku[9][9])
{
	for (int i = 0; i < 9; i ++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%i ", sudoku[i][j]);
			if (j == 8)
			printf("\n");
		}
	}
}

int is_valid(int x, int y, int n, int sudoku[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (sudoku[x][i] == n || sudoku[i][y] == n)
			return (0);
		i++;
	}
	return (1);
}

int solve(int sudoku[9][9])
{
	int x;
	int y;
	int n;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			if (sudoku[x][y] == 0)
			{
				n = 1;
				while (n < 10)
				{
					if (is_valid(x, y, n, sudoku))
					{
						sudoku[x][y] = n;
						if (solve(sudoku))
							return (1);
						sudoku[x][y] = 0;
					}
					n++;
				}
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int main()
{
	int sudoku[9][9] = { 
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0}, 
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};

	print_sudoku(sudoku);

	solve(sudoku);

	print_sudoku(sudoku);
}
