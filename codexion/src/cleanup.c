/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by dassunca          #+#    #+#             */
/*   Updated: 2026/11/03 14:05:51 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	destroy_dongles(t_sim *sim, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&sim->dongles[i].mutex);
		pthread_cond_destroy(&sim->dongles[i].cond);
		free(sim->dongles[i].heap.items);
		i++;
	}
	free(sim->dongles);
	sim->dongles = NULL;
}

void	destroy_coders(t_sim *sim, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&sim->coders[i].mutex);
		i++;
	}
	free(sim->coders);
	sim->coders = NULL;
}

void	sim_destroy(t_sim *sim)
{
	destroy_coders(sim, sim->cfg.n);
	destroy_dongles(sim, sim->cfg.n);
	pthread_mutex_destroy(&sim->ticket_mutex);
	pthread_mutex_destroy(&sim->log_mutex);
}
