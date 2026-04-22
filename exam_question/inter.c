/*
Escreva um programa que recebe duas strings e que as mostra, sem duplicados, 
os caracteres que aparecem em ambas as strings, na ordem que aparecem na primeira.
A exibição deve ser seguida de um '\n'.
Se o numero de parametros for diferente de 2, o programa exibe '\n'
*/

#include <unistd.h>

int main (int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *str1 = argv[1];
	char *str2 = argv[2];
	int rep = 0;
	int i = 0;
	int j = 0;
	int x = 0;

	while (str1[i])
	{
		rep = 0;
		j = 0;
		x = 0;
		// percorre os caracteres anteriores ao indice.
		while (x < i)
		{
			if (str1[x] == str1[i]) // Se o caracter já apareceu antes adiciona 1 no rep
				rep = 1; // Sinaliza que o str1[i] já apareceu anteriormente.
			x++;
		}
		// verifica se existe em str2
		while (str2[j])
		{
			if ((str1[i] == str2[j]) && rep == 0)
			{
				write (1, &str1[i], 1);
				rep = 1;
			}
			j++;
		}
		i++;
	}
	write (1, "\n", 1);
}
