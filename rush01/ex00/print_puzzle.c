#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(int nb);

/* size of puzzle, grid containing answers */
void	print_puzzle(int size, int **grid)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < size)
	{
		while (y < size)
		{
			ft_putnbr(grid[x][y]);
			if (y + 1 < size)
				write(1, " ", 1);
			y++;
		}
		y = 0;
		x++;
		write(1, "\n", 1);
	}
}
