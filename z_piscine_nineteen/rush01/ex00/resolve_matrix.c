int isvalid(int x, int y, int n, int matrix[4][4], char *str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (matrix[x][i] == n || matrix[i][y] == n)
			return (0);
		i++;
	}
	/*
	if (x == 3)
	{
		if(!check_from_above(y, matrix, str))
			return (0);
		if(!check_from_bottom)
			return (0);
	}
	if (y == 3)
	{
		if(!check_from_left)
			return (0);
		if(!check_from_right)
			return (0);
	}
	*/
	return (1);
}

int resolve_matrix(int matrix[4][4], char *str)
{
	int i;
	int j;
	int n;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matrix[i][j] == 0)
			{
				n = 1;
				while (n <= 4)
				{
					if (isvalid(i, j, n, matrix, str))
					{
						matrix[i][j] = n;
						if (resolve_matrix(matrix, str))
							return (1);
						matrix[i][j] = 0;
					}
					n++;
				}
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
