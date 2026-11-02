/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by login             #+#    #+#             */
/*   Updated: 2026/10/20 16:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static long	coder_key(t_coder *c)
{
	long	key;

	key = -1;
	if (c->sim->cfg.edf)
	{
		pthread_mutex_lock(&c->mutex);
		key = c->last_compile_start + c->sim->cfg.burnout;
		pthread_mutex_unlock(&c->mutex);
	}
	return (key);
}

static int	lone_coder(t_coder *c)
{
	while (!sim_stopped(c->sim))
		usleep(500);
	dongle_release(c->sim, c->first);
	return (0);
}

static int	take_both(t_coder *c)
{
	t_dongle	*first;
	t_dongle	*second;

	first = &c->sim->dongles[c->first];
	second = &c->sim->dongles[c->second];
	if (!acquire_pair(c, first, second, coder_key(c)))
		return (0);
	if (first == second)
	{
		log_state(c, MSG_TAKEN);
		return (lone_coder(c));
	}
	return (1);
}

void	*coder_routine(void *arg)
{
	t_coder	*c;

	c = (t_coder *)arg;
	if (c->id % 2 == 0)
		sleep_ms(c->sim, 1);
	while (!sim_stopped(c->sim))
	{
		if (!take_both(c))
			break ;
		do_compile(c);
		release_both(c);
		log_state(c, MSG_DEBUG);
		sleep_ms(c->sim, c->sim->cfg.debug);
		log_state(c, MSG_REFACTOR);
		sleep_ms(c->sim, c->sim->cfg.refactor);
	}
	return (NULL);
}
