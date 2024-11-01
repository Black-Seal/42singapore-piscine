#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	get_base_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (c != base[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	i = 0;
	j = 0;
	if (base[0] == '\0' || len == 1)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+'
			|| base[i] <= ' ' || base[i] == 127)
			return (0);
		i++;
	}
	return (1);
}

int	whitespace(char *str, int *ptr)
{
	int	i;
	int	state;

	i = 0;
	state = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			state *= -1;
		i++;
	}
	*ptr = i;
	return (state);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_len;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = whitespace(str, &i);
	base_len = ft_strlen(base);
	if (check_base(base) == 1)
	{
		while (str[i] != '\0' && get_base_digit(str[i], base) < base_len)
		{
			result = (result * base_len) + get_base_digit(str[i], base);
			i++;
		}
	}
	result *= sign;
	return (result);
}
