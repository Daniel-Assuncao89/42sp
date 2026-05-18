#include <unistd.h>

void    ft_putnbr(int nb)
{
    long	nbl; //long long somente no windows. Linux apenas long
    int		i;
    char	number[10];

    nbl = nb;
    i = 0;
    if (nbl < 0)
    {
        write(1, "-", 1);
        nbl *= -1;
    }
    while (nbl >= 10)
    {
        number[i++] = (nbl % 10) + '0';
        nbl = nbl / 10;
    }
    number[i] = nbl + '0';
    while (i >= 0)
    {
        write (1, &number[i--], 1);
    }
}

int main(void)
{
    ft_putnbr(457);
	write (1, "\n", 1);
	ft_putnbr(2147483647);
	write (1, "\n", 1);
	ft_putnbr(-2147483648);
	write (1, "\n", 1);
}
