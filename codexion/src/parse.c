/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by login             #+#    #+#             */
/*   Updated: 2026/10/20 16:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	read_num(char *s, long *out)
{
	size_t	len;
	size_t	i;

	len = strlen(s);
	if (len == 0 || len > 10)
		return (0);
	i = 0;
	while (i < len)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	if (len == 10 && strcmp(s, "2147483647") > 0)
		return (0);
	*out = atoi(s);
	return (1);
}

static void	fill_config(t_config *cfg, long *v)
{
	cfg->n = (int)v[0];
	cfg->burnout = v[1];
	cfg->compile = v[2];
	cfg->debug = v[3];
	cfg->refactor = v[4];
	cfg->required = v[5];
	cfg->cooldown = v[6];
}

int	parse_args(int argc, char **argv, t_config *cfg)
{
	long	v[7];
	int		i;

	if (argc != 9)
		return (usage());
	i = 0;
	while (i < 7)
	{
		if (!read_num(argv[i + 1], &v[i]))
			return (usage());
		i++;
	}
	if (v[0] < 1)
		return (usage());
	fill_config(cfg, v);
	return (parse_scheduler(argv[8], cfg));
}
