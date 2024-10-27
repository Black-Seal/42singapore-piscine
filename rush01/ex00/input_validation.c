#include <stdlib.h>
#include <unistd.h>

void	exit_program(void);

int	numeric_or_space(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	if (c == 32)
		return (2);
	return (0);
}

int	array_size(int size)
{
	int	array;

	array = 0;
	if (size % 4 == 0)
		array = size / 4;
	return (array);
}

int	input_len(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[a] != '\0')
	{
		if (a == 0 && numeric_or_space(str[a]) == 1)
			b++;
		if (numeric_or_space(str[a]) == 1 && numeric_or_space(str[a - 1]) == 2)
			b++;
		if (numeric_or_space(str[a]) == 0 || a > 30)
			return (0);
		a++;
	}
	return (b);
}

int	num_in_range(char *str, int grid_size)
{
	int		c;
	int		d;
	char	g_size;

	g_size = grid_size + '0';
	c = 0;
	d = 0;
	while (str[c] != '\0')
	{
		if (!(str[c] <= g_size) || (numeric_or_space(str[c]) <= 0))
			return (0);
		c++;
	}
	while (d < 21)
	{
		if (str[d] + str[d + 8] < 99 && str[d] + str[d + 8] > 101)
			return (0);
		d++;
	}
	return (1);
}

/* validates user input. return . 0 for error */
int	input_validation(int argc, char **argv)
{
	int	numarg;
	int	check;
	int	grid_size;

	if (argc == 2)
	{
		numarg = input_len(argv[1]);
		grid_size = array_size(numarg);
		check = num_in_range(argv[1], grid_size);
		if (grid_size == 0 || check == 0 || grid_size > 4)
			exit_program();
		return (grid_size);
	}
	write(1, "Error\n", 6);
	return (0);
}
