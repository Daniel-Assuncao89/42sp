#include <unistd.h>
int main (int argc, char **argv)
{
	int	size;

	size = 0;
	if (argc != 2)
		return write(1, "\n", 1);
	while (argv[1][size] != '\0')
		size++;
	while (size > 0)
	{
		size--; //decrementar antes de printar o caracter para não exibir ^@
		write(1, &argv[1][size], 1);
	}
	write (1, "\n", 1);
	return (argc);
}
