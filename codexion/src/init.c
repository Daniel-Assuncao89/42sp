/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by dassunca          #+#    #+#             */
/*   Updated: 2026/11/03 14:05:51 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	init_dongles(t_sim *sim)
{
	int	i;

	sim->dongles = malloc(sizeof(t_dongle) * sim->cfg.n);
	if (!sim->dongles)
		return (1);
	i = 0;
	while (i < sim->cfg.n)
	{
		if (dongle_init(&sim->dongles[i]))
		{
			destroy_dongles(sim, i);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	set_coder(t_sim *sim, int i)
{
	int	left;
	int	right;

	left = i;
	right = (i + 1) % sim->cfg.n;
	sim->coders[i].id = i + 1;
	sim->coders[i].sim = sim;
	sim->coders[i].last_compile_start = 0;
	sim->coders[i].compiles = 0;
	sim->coders[i].first = left;
	sim->coders[i].second = right;
	if (right < left)
	{
		sim->coders[i].first = right;
		sim->coders[i].second = left;
	}
}

static int	init_coders(t_sim *sim)
{
	int	i;

	sim->coders = malloc(sizeof(t_coder) * sim->cfg.n);
	if (!sim->coders)
		return (1);
	i = 0;
	while (i < sim->cfg.n)
	{
		set_coder(sim, i);
		if (pthread_mutex_init(&sim->coders[i].mutex, NULL))
		{
			destroy_coders(sim, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	sim_init(t_sim *sim)
{
	sim->stop = 0;
	sim->start = 0;
	sim->tickets = 0;
	sim->dongles = NULL;
	sim->coders = NULL;
	if (pthread_mutex_init(&sim->log_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&sim->ticket_mutex, NULL))
	{
		pthread_mutex_destroy(&sim->log_mutex);
		return (1);
	}
	if (init_dongles(sim) || init_coders(sim))
	{
		if (sim->dongles)
			destroy_dongles(sim, sim->cfg.n);
		pthread_mutex_destroy(&sim->ticket_mutex);
		pthread_mutex_destroy(&sim->log_mutex);
		return (1);
	}
	return (0);
}
