#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	test_ft_lowerandupper(int c)
{
	if (ft_tolower(c) == (c + 32))
		printf("Sucees tolower: %c\n", ft_tolower(c));
	else if(ft_toupper(c) == (c - 32))
		printf("Sucess toupper: %c\n", ft_toupper(c));
	else
		printf("Invalid params");
}

void    run_test(char *input, int (*f_libc)(const char*), int (*f_libft)(const char*))
{
    int expected;
    int result;

    expected = f_libc(input);
    result = f_libft(input);

    printf("Input    : \"%s\"\n", input);
    printf("Expected : %d\n", expected);
    printf("Result   : %d\n", result);

    if (expected == result)
        printf("Status   : OK\n");
    else
        printf("Status   : FAIL\n");

    printf("-----------------------------\n");
}

void	atoi_tester()
{
    run_test("42", atoi, ft_atoi);
    run_test("-42", atoi, ft_atoi);
    run_test("+42", atoi, ft_atoi);
    run_test("0", atoi, ft_atoi);
    run_test("   42", atoi, ft_atoi);
    run_test("\t\n\v\f\r 42", atoi, ft_atoi);

    run_test("--42", atoi, ft_atoi);
    run_test("-+42", atoi, ft_atoi);
    run_test("---42", atoi, ft_atoi);

    run_test("42abc", atoi, ft_atoi);
    run_test("abc42", atoi, ft_atoi);
    run_test("4a2", atoi, ft_atoi);
    run_test("a", atoi, ft_atoi);

    run_test("", atoi, ft_atoi);

    run_test("+", atoi, ft_atoi);
    run_test("-", atoi, ft_atoi);

    run_test("00042", atoi, ft_atoi);
    run_test("-00042", atoi, ft_atoi);
    run_test("000", atoi, ft_atoi);

    run_test("2147483647", atoi, ft_atoi);
    run_test("-2147483648", atoi, ft_atoi);

    run_test("+ 42", atoi, ft_atoi);
    run_test("- 42", atoi, ft_atoi);
}

int	main(void)
{
	test_ft_lowerandupper('A');
	test_ft_lowerandupper('a');
	test_ft_lowerandupper(1);
	atoi_tester();
}
