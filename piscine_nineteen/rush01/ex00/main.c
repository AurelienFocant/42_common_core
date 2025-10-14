void	ft_putstr(char *str);
void	build_empty_matrix(int matrix[4][4]);
void	fill_matrix(int matrix[4][4], char *str);
int		resolve_matrix(int matrix[4][4], char* argv);
void	print_matrix(int matrix[4][4]);

int	main(int argc, char **argv)
{
	int matrix[4][4];

	if (argc != 2)
	{
		ft_putstr("ERROR\n");
		return (1);
	}
	build_empty_matrix(matrix);
	fill_matrix(matrix, argv[1]);
	resolve_matrix(matrix, argv[1]);
	print_matrix(matrix);
	return (0);
}
