/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by dassunca          #+#    #+#             */
/*   Updated: 2026/11/03 14:05:51 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	all_done(t_sim *sim)
{
	int		i;
	long	compiles;

	i = 0;
	while (i < sim->cfg.n)
	{
		pthread_mutex_lock(&sim->coders[i].mutex);
		compiles = sim->coders[i].compiles;
		pthread_mutex_unlock(&sim->coders[i].mutex);
		if (compiles < sim->cfg.required)
			return (0);
		i++;
	}
	return (1);
}

static int	find_burnout(t_sim *sim)
{
	int		i;
	long	last;

	i = 0;
	while (i < sim->cfg.n)
	{
		pthread_mutex_lock(&sim->coders[i].mutex);
		last = sim->coders[i].last_compile_start;
		pthread_mutex_unlock(&sim->coders[i].mutex);
		if (sim_time(sim) - last >= sim->cfg.burnout)
		{
			log_burnout(sim, sim->coders[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_sim	*sim;

	sim = (t_sim *)arg;
	while (!sim_stopped(sim))
	{
		if (all_done(sim))
			break ;
		if (find_burnout(sim))
			break ;
		usleep(500);
	}
	sim_stop(sim);
	return (NULL);
}
