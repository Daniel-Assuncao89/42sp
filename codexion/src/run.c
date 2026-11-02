/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by login             #+#    #+#             */
/*   Updated: 2026/10/20 16:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	spawn_coders(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->cfg.n)
	{
		if (pthread_create(&sim->coders[i].thread, NULL,
				coder_routine, &sim->coders[i]))
			return (i);
		i++;
	}
	return (i);
}

static void	join_all(t_sim *sim, int started, int monitor_on)
{
	int	i;

	if (monitor_on)
		pthread_join(sim->monitor, NULL);
	i = 0;
	while (i < started)
	{
		pthread_join(sim->coders[i].thread, NULL);
		i++;
	}
}

int	sim_run(t_sim *sim)
{
	int	started;
	int	monitor_on;

	sim->start = now_ms();
	started = spawn_coders(sim);
	monitor_on = 0;
	if (started == sim->cfg.n)
		monitor_on = !pthread_create(&sim->monitor, NULL,
				monitor_routine, sim);
	if (!monitor_on)
	{
		sim_stop(sim);
		fprintf(stderr, "Error: could not create threads\n");
	}
	join_all(sim, started, monitor_on);
	return (!monitor_on);
}
