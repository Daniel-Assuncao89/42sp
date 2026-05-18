#include <unistd.h>

int main (int argc, char **argv)
{
	int	i = 0;
	int	x = 0;
	int y = 0;
	int	rep = 0;

	if (argc == 3)
	{	
		while (argv[1][i] != '\0')
		{
			x = 0;
			y = 0;
			rep = 0;
			while (x < i)
			{
				if (argv[1][x] == argv[1][i])
					rep = 1;
				x++;
			}
			while (argv[2][y] != '\0')
			{
				if ((argv[1][i] == argv[2][y]) && rep == 0)
				{
					write (1, &argv[1][i], 1);
					rep = 1;
				}
				y++;
			}
			i++;
		}
		write (1, "\n", 1);
		return (argc);
	}
	write (1, "\n", 1);
	return (0);
}
