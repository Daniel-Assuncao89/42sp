#include "push_swap.h"

static int	ps_streq(char *s1, char *s2)
{
    /**
     * Compara duas strings, retorna 1 se forem iguais, 0 se forem diferentes.
     * Retorna 1 se s1 e s2 forem iguais, 0 se forem diferentes.
     * |-> Pode ser substitudo por ft_strcmp da libft.
     */
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == '\0' && s2[i] == '\0');
}

int	is_flag(char *str)
{
	return (str[0] == '-' && str[1] == '-');
}

static int	set_strategy(t_input *input, t_strategy strategy)
{
    /**
     * Valida se o usuario já passou alguma estrategia, se sim retorna 0.
     * Seta a estrategia escolhida pelo usuario na struct t_input.
     */
	if (input->has_strategy)
		return (0);
	input->strategy = strategy;
	input->has_strategy = 1;
	return (1);
}

int	parse_flag(char *str, t_input *input)
{
    /**
     * Valida se a flag é valida, se não for retorna 0.
     * Se for valida, seta a estrategia escolhida pelo usuario na struct t_input.
     */
	if (ps_streq(str, "--bench"))
	{
		if (input->bench)
			return (0);
		input->bench = 1;
		return (1);
	}
	if (ps_streq(str, "--simple"))
		return (set_strategy(input, STRATEGY_SIMPLE));
	if (ps_streq(str, "--medium"))
		return (set_strategy(input, STRATEGY_MEDIUM));
	if (ps_streq(str, "--complex"))
		return (set_strategy(input, STRATEGY_COMPLEX));
	if (ps_streq(str, "--adaptive"))
		return (set_strategy(input, STRATEGY_ADAPTIVE));
	return (0);
}