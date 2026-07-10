#include "push_swap.h"

static char	*strategy_to_str(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("--simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("--medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("--complex");
	if (strategy == STRATEGY_ADAPTIVE)
		return ("--adaptive");
	return ("unknown");
}

static void	print_input(t_input *input)
{
	int	i;

	printf("=== PARSING RESULT ===\n");
	printf("strategy: %s\n", strategy_to_str(input->strategy));
	printf("has_strategy: %d\n", input->has_strategy);
	printf("bench: %d\n", input->bench);
	printf("size: %d\n", input->size);
	i = 0;
	while (i < input->size)
	{
		printf("values[%d]: %d\n", i, input->values[i]);
		i++;
	}
	printf("======================\n");
}

int	main(int argc, char **argv)
{
	t_input	input;

	printf("MAIN START\n");
	printf("argc: %d\n", argc);
	if (argc == 1)
	{
		printf("NO ARGS\n");
		return (0);
	}
	printf("BEFORE PARSE\n");
	if (!parse_input(argc, argv, &input))
	{
		printf("PARSE FAILED\n");
		free_input(&input);
		print_error();
		return (1);
	}
	printf("PARSE OK\n");
	print_input(&input);
	free_input(&input);
	return (0);
}
// ====== CÓDIGO ACIMA É SÓ PARA TESTAR O PARSING, REMOVER DEPOIS ======
// int	main(int argc, char **argv)
// {
// 	t_input	input;

// 	printf("MAIN START\n");

// 	if (argc == 1)
// 		return (0);
// 	if (!parse_input(argc, argv, &input))
// 	{
// 		printf("ave");
// 		free_input(&input);
// 		print_error();
// 		return (1);
// 	}
// 	/*
// 		Aqui monta a stack A usando:
// 			input.values
// 			input.size

// 		E escolhe o algoritmo com:
// 			input.strategy

// 		Se input.bench == 1:
// 			as métricas devem ser impressas em stderr após a ordenação.
// 	*/
// 	free_input(&input);
// 	return (0);
// }