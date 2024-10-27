#include <stdlib.h>
#include <unistd.h>

void	exit_program(void);
int		parse_views(char *str, int *views);
int		is_valid_placement(int **grid, int row, int col, int num);
int		check_line_visibility(int **grid, int index,
			int is_column, int expected);
int		check_line_visibility_reverse(int **grid, int index,
			int is_column, int expected);
void	print_puzzle(int size, int **grid);

int	check_line_visibility(int **grid, int index, int is_column, int expected)
{
	int		max;
	int		count;
	int		i;
	int		reverse;
	int		value;

	max = 0;
	count = 0;
	reverse = 0;
	i = 0;
	while (i < 4)
	{
		if (is_column)
			value = grid[i][index];
		else
			value = grid[index][i];
		if (value > max)
		{
			max = value;
			count++;
		}
		i++;
	}
	return (count == expected);
}

int	check_line_visibility_reverse(int **grid, int index,
		int is_column, int expected)
{
	int	max;
	int	count;
	int	i;
	int	reverse;
	int	value;

	max = 0;
	count = 0;
	reverse = 1;
	i = 3;
	while (i >= 0)
	{
		if (is_column)
			value = grid[i][index];
		else
			value = grid[index][i];
		if (value > max)
		{
			max = value;
			count++;
		}
		i--;
	}
	return (count == expected);
}

/* Check column visibility from top and bottom first, then
check row visibility from left and right */
int	check_visibility(int **grid, int size, int *views)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (col < size)
	{
		if (!check_line_visibility(grid, col, 1, views[col]))
			return (0);
		if (!check_line_visibility_reverse(grid, col, 1, views[size + col]))
			return (0);
		col++;
	}
	while (row < size)
	{
		if (!check_line_visibility(grid, row, 0,
				views[2 * size + row]))
			return (0);
		if (!check_line_visibility_reverse(grid, row, 0,
				views[3 * size + row]))
			return (0);
		row++;
	}
	return (1);
}

int	solve(int **grid, int size, int *views, int cell)
{
	int	row;
	int	col;
	int	i;

	row = cell / size;
	col = cell % size;
	if (cell == size * size)
		return ((check_visibility(grid, size, views)));
	i = 1;
	while (i <= size)
	{
		if (is_valid_placement(grid, row, col, i))
		{
			grid[row][col] = i;
			if (solve(grid, size, views, cell + 1))
				return (1);
			grid[row][col] = 0;
		}
		i++;
	}
	return (0);
}

int	solve_puzzle(int **grid, int size, char *str)
{
	int	views[16];

	if (parse_views(str, views) == 0)
		exit_program();
	if (solve(grid, size, views, 0))
	{
		print_puzzle(size, grid);
		return (1);
	}
	exit_program();
	return (0);
}
