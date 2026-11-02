/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by login             #+#    #+#             */
/*   Updated: 2026/10/20 16:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static long	next_ticket(t_sim *sim)
{
	long	ticket;

	pthread_mutex_lock(&sim->ticket_mutex);
	ticket = sim->tickets++;
	pthread_mutex_unlock(&sim->ticket_mutex);
	return (ticket);
}

static long	pair_wait(t_coder *c, t_dongle *f, t_dongle *s)
{
	long	now;
	long	wait;

	if (!dongle_is_top(c, f) || !dongle_is_top(c, s))
		return (-1);
	now = sim_time(c->sim);
	wait = f->available_at - now;
	if (s->available_at - now > wait)
		wait = s->available_at - now;
	if (wait < 0)
		wait = 0;
	return (wait);
}

static void	grab(t_dongle *d)
{
	heap_pop(&d->heap);
	d->in_use = 1;
}

static long	try_take(t_coder *c, t_dongle *f, t_dongle *s)
{
	long	wait;

	if (s != f)
		pthread_mutex_lock(&s->mutex);
	wait = pair_wait(c, f, s);
	if (wait == 0)
	{
		grab(f);
		if (s != f)
			grab(s);
	}
	if (s != f)
		pthread_mutex_unlock(&s->mutex);
	return (wait);
}

int	acquire_pair(t_coder *c, t_dongle *f, t_dongle *s, long key)
{
	long			wait;
	long			ticket;
	struct timespec	ts;

	ticket = next_ticket(c->sim);
	if (!dongle_enqueue(c, f, key, ticket)
		|| (s != f && !dongle_enqueue(c, s, key, ticket)))
		return (0);
	pthread_mutex_lock(&f->mutex);
	wait = -1;
	while (!sim_stopped(c->sim))
	{
		wait = try_take(c, f, s);
		if (wait == 0)
			break ;
		if (wait > 0)
		{
			abs_timeout(&ts, wait);
			pthread_cond_timedwait(&f->cond, &f->mutex, &ts);
		}
		else
			pthread_cond_wait(&f->cond, &f->mutex);
	}
	pthread_mutex_unlock(&f->mutex);
	return (wait == 0);
}
