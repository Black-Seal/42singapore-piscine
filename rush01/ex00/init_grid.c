#include <stdlib.h>
#include <unistd.h>

void	exit_program(void);

/* inits grid filled with NULL characters */
int	**init_grid(int size)
{
	int	**grid;
	int	x;
	int	y;

	x = 0;
	y = 0;
	grid = (int **)malloc(size * sizeof(int *));
	if (grid == NULL)
		exit_program();
	while (x < size)
	{
		grid[x] = (int *)malloc(size * sizeof(int));
		if (grid[x] == NULL)
			exit_program();
		x++;
	}
	return (grid);
}
