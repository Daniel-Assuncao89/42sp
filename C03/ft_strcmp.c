#include <stdio.h>
#include <string.h>

// int ft_strcmp(char *s1, char *s2)
// {
//     int count;
//     int str_ascii_value;

//     count = 0;
//     while((s1[count] && s2[count]) && (s1[count] == s2[count]))
//     {
//         count++;
//     }
//     str_ascii_value = s1[count] - s2[count];
//     return (str_ascii_value);
// }
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int main (void)
{
    printf("Exercice 00 : ft_strcmp \n\n");
    char str1[] = "cma", str2[] = "cam";
    printf("Result: %d\n\n", ft_strcmp(str1, str2));
    printf("Expected outcome: %d \n", strcmp(str1, str2));
}