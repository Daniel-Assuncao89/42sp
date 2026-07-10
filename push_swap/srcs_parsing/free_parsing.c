#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_input(t_input *input)
{
	if (!input)
		return ;
	if (input->values)
		free(input->values);
	input->values = NULL;
	input->size = 0;
	input->strategy = STRATEGY_ADAPTIVE;
	input->has_strategy = 0;
	input->bench = 0;
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}