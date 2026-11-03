/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by dassunca          #+#    #+#             */
/*   Updated: 2026/11/03 14:05:51 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_sim	sim;
	int		ret;

	if (parse_args(argc, argv, &sim.cfg))
		return (1);
	if (sim_init(&sim))
	{
		fprintf(stderr, "Error: initialization failed\n");
		return (1);
	}
	ret = sim_run(&sim);
	sim_destroy(&sim);
	return (ret);
}
