/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by login             #+#    #+#             */
/*   Updated: 2026/10/20 16:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	dongle_init(t_dongle *d)
{
	if (pthread_mutex_init(&d->mutex, NULL))
		return (1);
	if (pthread_cond_init(&d->cond, NULL))
	{
		pthread_mutex_destroy(&d->mutex);
		return (1);
	}
	if (heap_init(&d->heap, 2))
	{
		pthread_cond_destroy(&d->cond);
		pthread_mutex_destroy(&d->mutex);
		return (1);
	}
	d->in_use = 0;
	d->available_at = 0;
	return (0);
}

int	dongle_is_top(t_coder *c, t_dongle *d)
{
	t_req	*top;

	top = heap_peek(&d->heap);
	return (top && top->coder_id == c->id && !d->in_use);
}

int	dongle_enqueue(t_coder *c, t_dongle *d, long key, long ticket)
{
	int	ok;

	pthread_mutex_lock(&d->mutex);
	ok = heap_push(&d->heap, key, ticket, c->id);
	pthread_mutex_unlock(&d->mutex);
	return (ok);
}

void	dongle_notify(t_sim *sim, int idx)
{
	int	i;
	int	j;

	i = -1;
	while (i <= 1)
	{
		j = (idx + i + sim->cfg.n) % sim->cfg.n;
		pthread_mutex_lock(&sim->dongles[j].mutex);
		pthread_cond_broadcast(&sim->dongles[j].cond);
		pthread_mutex_unlock(&sim->dongles[j].mutex);
		i++;
	}
}

void	dongle_release(t_sim *sim, int idx)
{
	t_dongle	*d;

	d = &sim->dongles[idx];
	pthread_mutex_lock(&d->mutex);
	d->in_use = 0;
	d->available_at = sim_time(sim) + sim->cfg.cooldown;
	pthread_mutex_unlock(&d->mutex);
	dongle_notify(sim, idx);
}
