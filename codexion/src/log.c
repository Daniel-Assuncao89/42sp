/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by dassunca          #+#    #+#             */
/*   Updated: 2026/11/03 14:05:51 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "codexion.h"

int	sim_stopped(t_sim *sim)
{
	int	stopped;

	pthread_mutex_lock(&sim->log_mutex);
	stopped = sim->stop;
	pthread_mutex_unlock(&sim->log_mutex);
	return (stopped);
}

void	log_state(t_coder *c, char *msg)
{
	t_sim	*sim;

	sim = c->sim;
	pthread_mutex_lock(&sim->log_mutex);
	if (!sim->stop)
		printf("%ld %d %s\n", sim_time(sim), c->id, msg);
	pthread_mutex_unlock(&sim->log_mutex);
}

void	log_burnout(t_sim *sim, int id)
{
	pthread_mutex_lock(&sim->log_mutex);
	if (!sim->stop)
	{
		sim->stop = 1;
		printf("%ld %d burned out\n", sim_time(sim), id);
	}
	pthread_mutex_unlock(&sim->log_mutex);
}

void	wake_all(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->cfg.n)
	{
		pthread_mutex_lock(&sim->dongles[i].mutex);
		pthread_cond_broadcast(&sim->dongles[i].cond);
		pthread_mutex_unlock(&sim->dongles[i].mutex);
		i++;
	}
}

void	sim_stop(t_sim *sim)
{
	pthread_mutex_lock(&sim->log_mutex);
	sim->stop = 1;
	pthread_mutex_unlock(&sim->log_mutex);
	wake_all(sim);
}
