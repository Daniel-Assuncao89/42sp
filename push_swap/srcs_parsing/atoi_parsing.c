#include "push_swap.h"

static int	ps_isdigit(char c) //Pode usar da libft aqui.
{
	return (c >= '0' && c <= '9');
}

static int	check_limit(long long num, int sign)
{
	if (sign == 1 && num > 2147483647)
		return (0);
	if (sign == -1 && num > 2147483648)
		return (0);
	return (1);
}

int	ft_atoi_ps(char *str, int *result)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ps_isdigit(str[i]))
			return (0);
		num = (num * 10) + (str[i] - '0');
		if (!check_limit(num, sign))
			return (0);
		i++;
	}
	*result = (int)(num * sign);
	return (1);
}