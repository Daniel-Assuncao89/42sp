#include "push_swap.h"

void	init_input(t_input *input)
{
	/**
	 * Inicializa a struct t_input com valores default.
	 * values = NULL, size = 0, strategy = STRATEGY_ADAPTIVE, has_strategy = 0, bench = 0
	 * Retorna void.
	 */
	input->values = NULL;
	input->size = 0;
	input->strategy = STRATEGY_ADAPTIVE;
	input->has_strategy = 0;
	input->bench = 0;
}

int	parse_input(int argc, char **argv, t_input *input)
{
	/**
	 * Faz a primeira leitura dos argumentos, conta quantos numeros existem para alocar o array de inteiros.
	 * Faz a segunda leitura dos argumentos, salva os numeros no array de inteiros.
	 * Retorna 1 se tudo ok, 0 se algum erro.
	 */
	int	total;

	init_input(input);
	if (!count_input(argc, argv, input))
		return (0);
	total = input->size;
	input->values = malloc(sizeof(int) * total);
	if (!input->values)
		return (0);
	input->size = 0;
	if (!fill_input(argc, argv, input))
		return (0);
	return (1);
}