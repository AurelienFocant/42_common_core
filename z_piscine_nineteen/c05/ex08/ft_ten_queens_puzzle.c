#include <unistd.h>
#include <stdio.h>

# define N 5

void	ft_fill_null(int matrix[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			matrix[i][j] = 0;	
			j++;
		}
		i++;
	}
}

void	ft_print_board(int matrix[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			printf("%i ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_print_positions(int board[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (board[i][j] == 1)
				printf("%i", j);
			j++;
		}
		i++;
	}
	printf("\n");
}

int	ft_check_column(int x, int board[N][N])
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (board[i][x] == 1)
			return (0);
		i++;
	}

	return (1);
}

int	ft_check_row(int y, int board[N][N])
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (board[y][i] == 1)
			return (0);
		i++;
	}

	return (1);
}

int	ft_check_pos_diag(int y, int x, int board[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (i + j == y + x && board[i][j] == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_neg_diag(int y, int x, int board[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (i - j == y - x && board[i][j] == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isvalid(int y, int x, int board[N][N])
{
	int	tmp;

	tmp = board[y][x];
	board[y][x] = 0;

	if (!ft_check_column(x, board))
		return (0);
	if (!ft_check_row(y, board))
		return (0);
	if (!ft_check_neg_diag(y, x, board))
		return (0);
	if (!ft_check_pos_diag(y, x, board))
		return (0);


	board[y][x] = tmp;
	return (1);
}

int	ft_solve_puzzle(int board[N][N], int y)
{
	int	x;
	int	count_solutions;

	if (y == N)
	{
		ft_print_board(board);
		ft_print_positions(board);
		printf("\n");
		return (count_solutions = 1);
	}
	count_solutions = 0;
	x = 0;
	while (x < N)
	{
		if (ft_isvalid(y, x, board))
		{
			board[y][x] = 1;
			count_solutions += (ft_solve_puzzle(board, ++y));
			board[--y][x] = 0;
		}
		x++;
	}
	return count_solutions;
}

int	ft_ten_queens_puzzle(void)
{
	int	board[N][N];
	ft_fill_null(board);

	printf("nb sol: %i\n", ft_solve_puzzle(board, 0));

	return (0);
}

int main(void)
{
	ft_ten_queens_puzzle();
}
