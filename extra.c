
#include "push_swap.h"

static int	long_number64(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	extra_atoi(const char *str)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == ' ' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (number > (LONG_MAX - (str[i] - '0')) / 10)
			return (long_number64(sign));
		number = (number * 10) + (str[i] - '0');
		if ((number * sign) > 2147483647 || (number * sign) < -2147483648)
			ft_exit("Out of range");
		i++;
	}
	return (number * sign);
}

void    *ft_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_exit("Failed to Allocate");
	ft_free(ptr);
	return (ptr);
}

void    ft_free(void *ptr)
{
	static  void *total[INT_MAX];
	static  int in;
	int         out;

	out = 0;
	if (!ptr)
		while (total[out])
			free(total[out++]);
	else
		total[++in] = ptr;
}

void    ft_exit(char *why)
{
	ft_free(NULL);
	if (why)
	{
		printf("\033[1;31mE: %s\033[0m\n", why);
		exit(1);
	}
	exit(0);
}
