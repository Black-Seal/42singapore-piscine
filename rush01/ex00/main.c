#include <stdlib.h>
#include <unistd.h>

/* size of puzzle, 2d array of puzzle*/

int		**make_grid(int size, char **argv);
int		**init_grid(int size);
void	print_puzzle(int size, int **grid);
int		input_validation(int argc, char **argv);

int		solve_puzzle(int **grid, int size, char *str);
int		solve(int **grid, int size, int *views, int cell);
int		is_valid_placement(int **grid, int row, int col, int num);
int		check_visibility(int **grid, int size, int *views);
int		check_line_visibility(int **grid, int index,
			int is_column, int expected);
int		check_line_visibility_reverse(int **grid, int index,
			int is_column, int expected);

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	exit_program(void);

int	main(int argc, char **argv)
{
	int	puzzle_size;
	int	**grid;
	int	i;

	puzzle_size = input_validation(argc, argv);
	if (puzzle_size > 0)
	{
		grid = init_grid(puzzle_size);
		if (solve_puzzle(grid, puzzle_size, argv[1]) == 0)
			exit_program();
		i = 0;
		while (i < puzzle_size)
		{
			free(grid[i]);
			i++;
		}
		free(grid);
	}
	return (0);
}
