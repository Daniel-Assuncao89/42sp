/*char	*swap_cases(char *str)
{
	int i = 0;
	char str_c[50];
	char comp;
	char *str_ptr;
	while (str[i] != '\0')
	{
		if(str[i] >= 97 && str[i] <= 122)
		{
			comp = 'a';
			while (str[i] != comp)
			{
				comp++;
			}
			str_c[i] = comp - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			comp = 'A';
			while ( str[i] != '\0')
			{
				comp++;
			}
		str_c[i] = str[i];
		}
		else
		{
			str_c[i] = str[i];
		}
	i++;
	}
	str_c[i] = '\0';
	str_ptr = str_c;
	return (str_ptr);
Minha solucao na prova que deu errado*/

// Solução GPT
#include <unistd.h>
char *swap_cases(char *str)
{
    int i = 0;

    if (!str)
        return (0);

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}

int main(void)
{
    char str[] = "AbC123xYz";
    int i;

    swap_cases(str);

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}

/* //Main recebendo argumentos do usuario
int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        swap_cases(argv[1]);
        while (argv[1][i])
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
*/
