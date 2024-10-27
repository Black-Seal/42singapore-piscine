#include <stdlib.h>
#include <unistd.h>

void	exit_program(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

int	is_valid_placement(int **grid, int row, int col, int num)
{
	int	i;
	int	size;

	i = 0;
	size = 4;
	while (i < size)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	parse_views(char *str, int *views)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (str[i] != '\0' && pos < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
			views[pos++] = str[i] - '0';
		i++;
	}
	if (pos == 16)
		return (1);
	else
		return (0);
}
