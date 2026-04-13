#include <stdio.h>
#include <string.h>
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int count;
    int str_ascii_value;

    count = 0;
    while (s1[count] && count < n)
    {
        if (s1[count] != s2[count])
        {
            str_ascii_value = s1[count] - s2[count];
        }
        count++;
    }
    if (n == 0)
        return (0);
    else
        return (str_ascii_value);
}

int main (void)
{
    printf("Exercice 01 : ft_strncmp \n\n");
    char str1[] = "13443", str2[] = "13345";
    int nbr = 4;
    printf("Result: %d\n\n", ft_strncmp(str1, str2, nbr));
    printf("Expected outcome: %d \n", strncmp(str1, str2, nbr));
}