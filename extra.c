
#include "push_swap.h"

static int	long_result64(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int		extra_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (*str && ((*str >= 9 && *str <= 13) || (*str == 32)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (long_result64(sign));
		result = (result * 10) + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			ft_exit("Out of range");
		i++;
	}
	return (result * sign);
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

void	error(char *err)
{
	while (*err)
	{
		write(2, err, 1);
		err++;
	}
}

void    ft_exit(char *why)
{
	ft_free(NULL);
	if (why)
	{
		error("\033[1;31m");
		error("E: ");
		error(why);
		error("\033[0m\n");
		exit(1);
	}
	exit(0);
}
