/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by login             #+#    #+#             */
/*   Updated: 2026/10/20 16:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	usage(void)
{
	fprintf(stderr, "Usage: ./codexion number_of_coders time_to_burnout "
		"time_to_compile time_to_debug time_to_refactor "
		"number_of_compiles_required dongle_cooldown scheduler\n");
	fprintf(stderr, "All numbers must be non-negative integers "
		"(number_of_coders >= 1); scheduler is 'fifo' or 'edf'.\n");
	return (1);
}

int	parse_scheduler(char *s, t_config *cfg)
{
	if (strcmp(s, "fifo") == 0)
		cfg->edf = 0;
	else if (strcmp(s, "edf") == 0)
		cfg->edf = 1;
	else
		return (usage());
	return (0);
}
