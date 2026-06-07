#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void    run_test_char(char *input, int (*f_libc)(const char*), int (*f_libft)(const char*))
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

void    run_test_int(int input, int (*f_libc)(int), int (*f_libft)(int))
{
    int expected;
    int result;

    expected = f_libc(input);
    result = f_libft(input);

    printf("Input    : %d\n", input);
    printf("Expected : %d\n", expected);
    printf("Result   : %d\n", result);

    if (expected == result)
        printf("Status   : OK\n");
    else
        printf("Status   : FAIL\n");

    printf("-----------------------------\n");
}
void	ft_basic_functions_tester()
{
	run_test_int('a', isalpha, ft_isalpha);
	run_test_int('1', isdigit, ft_isdigit);
	run_test_int('A', isalnum, ft_isalnum);
	run_test_int('1', isalnum, ft_isalnum);
	run_test_int(32, isascii, ft_isascii);
	run_test_int(0, isascii, ft_isascii);
}
void	atoi_tester()
{
    run_test_char("42", atoi, ft_atoi);
    run_test_char("-42", atoi, ft_atoi);
    run_test_char("+42", atoi, ft_atoi);
    run_test_char("0", atoi, ft_atoi);
    run_test_char("   42", atoi, ft_atoi);
    run_test_char("\t\n\v\f\r 42", atoi, ft_atoi);
    run_test_char("--42", atoi, ft_atoi);
    run_test_char("-+42", atoi, ft_atoi);
    run_test_char("---42", atoi, ft_atoi);
    run_test_char("42abc", atoi, ft_atoi);
    run_test_char("abc42", atoi, ft_atoi);
    run_test_char("4a2", atoi, ft_atoi);
    run_test_char("a", atoi, ft_atoi);
    run_test_char("", atoi, ft_atoi);
    run_test_char("+", atoi, ft_atoi);
    run_test_char("-", atoi, ft_atoi);
    run_test_char("00042", atoi, ft_atoi);
    run_test_char("-00042", atoi, ft_atoi);
    run_test_char("000", atoi, ft_atoi);
    run_test_char("2147483647", atoi, ft_atoi);
    run_test_char("-2147483648", atoi, ft_atoi);
    run_test_char("+ 42", atoi, ft_atoi);
    run_test_char("- 42", atoi, ft_atoi);
}

int	main(void)
{
	ft_basic_functions_tester();
	//atoi_tester();
}
