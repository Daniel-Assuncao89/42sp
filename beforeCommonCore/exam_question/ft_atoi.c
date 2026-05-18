int ft_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <=13) || str[i] == 32)
		i++;
	return (i);
}

#include <stdio.h>
int	ft_atoi(char *str)
{
	int	i = 0;
	int	number = 0;
	int minus = 0;

	i = ft_space(str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus += 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	if (minus % 2 == 1)
		number *= -1;
	return (number);
}

int     main(void)
{
    printf("Expected 123: %d\n", ft_atoi("123+456"));
    printf("Expected -1234: %d\n", ft_atoi("   ---+--1234ab567"));
    printf("Expected 42: %d\n", ft_atoi("   +42"));
    printf("Expected -123: %d\n", ft_atoi("   -+--+123"));
    printf("Expected 123: %d\n", ft_atoi("   00000123"));
    printf("Expected -42: %d\n", ft_atoi("   +-42"));
    return (0);
}

