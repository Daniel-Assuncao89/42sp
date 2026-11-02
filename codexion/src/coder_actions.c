/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by login             #+#    #+#             */
/*   Updated: 2026/10/20 16:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	log_compile(t_coder *c)
{
	t_sim	*sim;
	long	t;

	sim = c->sim;
	pthread_mutex_lock(&sim->log_mutex);
	if (!sim->stop)
	{
		t = sim_time(sim);
		printf("%ld %d %s\n", t, c->id, MSG_TAKEN);
		printf("%ld %d %s\n", t, c->id, MSG_TAKEN);
		printf("%ld %d %s\n", t, c->id, MSG_COMPILE);
	}
	pthread_mutex_unlock(&sim->log_mutex);
}

void	do_compile(t_coder *c)
{
	pthread_mutex_lock(&c->mutex);
	c->last_compile_start = sim_time(c->sim);
	pthread_mutex_unlock(&c->mutex);
	log_compile(c);
	sleep_ms(c->sim, c->sim->cfg.compile);
	pthread_mutex_lock(&c->mutex);
	c->compiles++;
	pthread_mutex_unlock(&c->mutex);
}

void	release_both(t_coder *c)
{
	dongle_release(c->sim, c->first);
	if (c->first != c->second)
		dongle_release(c->sim, c->second);
}
