#include <stdlib.h>

typedef struct skyler {
	size_t		i;
	int			sign;
	long long	result;
}	t_need;

int	ft_atoi(const char *str)
{
	t_need	x;

	x.sign = 1;
	x.result = 0;
	x.i = 0;
	while (str[x.i] == 32 || (str[x.i] >= 9 && str[x.i] <= 13))
		x.i++;
	if (str[x.i] == '-')
	{
		x.sign = -1;
		x.i++;
	}
	else if (str[x.i] == '+')
		x.i++;
	while (str[x.i] >= '0' && str[x.i] <= '9')
	{
		x.result = x.result * 10 + str[x.i] - '0';
		x.i++;
	}
	if ((unsigned long long)x.result > 9223372036854775807 && x.sign == -1)
		return (0);
	if ((unsigned long long)x.result > 9223372036854775807)
		return (-1);
	return (x.result * x.sign);
}