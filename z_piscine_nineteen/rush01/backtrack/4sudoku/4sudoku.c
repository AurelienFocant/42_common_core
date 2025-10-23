#include <stdio.h>

void print_sudoku(int sudoku[4][4])
{
	for (int i = 0; i < 4; i ++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%i ", sudoku[i][j]);
			if (j == 3)
			printf("\n");
		}
	}
}

int is_valid(int x, int y, int n, int sudoku[4][4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (sudoku[x][i] == n)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (sudoku[i][y] == n)
			return (0);
		i++;
	}
	return (1);
}

int solve(int sudoku[4][4])
{
	int x;
	int y;
	int n;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (sudoku[x][y] == 0)
			{
				n = 1;
				while (n < 5)
				{
					if (is_valid(x, y, n, sudoku))
					{
						sudoku[x][y] = n;
						//print_sudoku(sudoku);
						//printf("\n");
						if(solve(sudoku))
							return 1;
						//printf("on met des 0\n");
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

void fill_arr(int arr[4][4])
{
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			arr[i][j] = 3;		
}


int main()
{
	int sudoku[4][4] = { 
		{0, 4, 0, 0},
		{0, 3, 0, 0},
		{0, 0, 4, 0},
		{0, 0, 1, 0}
	};

	solve(sudoku);
	//fill_arr(sudoku);

	print_sudoku(sudoku);

}
