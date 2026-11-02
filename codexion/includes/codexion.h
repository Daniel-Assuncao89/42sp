/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by login             #+#    #+#             */
/*   Updated: 2026/10/20 16:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <time.h>

# define MSG_TAKEN "has taken a dongle"
# define MSG_COMPILE "is compiling"
# define MSG_DEBUG "is debugging"
# define MSG_REFACTOR "is refactoring"

typedef struct s_sim	t_sim;

typedef struct s_config
{
	int		n;
	long	burnout;
	long	compile;
	long	debug;
	long	refactor;
	long	required;
	long	cooldown;
	int		edf;
}	t_config;

typedef struct s_req
{
	long	key;
	long	seq;
	int		coder_id;
}	t_req;

typedef struct s_heap
{
	t_req	*items;
	int		size;
	int		cap;
}	t_heap;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	t_heap			heap;
	int				in_use;
	long			available_at;
}	t_dongle;

typedef struct s_coder
{
	int				id;
	int				first;
	int				second;
	long			last_compile_start;
	long			compiles;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	t_sim			*sim;
}	t_coder;

struct s_sim
{
	t_config		cfg;
	long			start;
	int				stop;
	long			tickets;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	ticket_mutex;
	t_dongle		*dongles;
	t_coder			*coders;
	pthread_t		monitor;
};

/* parse.c / parse_utils.c */
int		parse_args(int argc, char **argv, t_config *cfg);
int		usage(void);
int		parse_scheduler(char *s, t_config *cfg);

/* time_utils.c */
long	now_ms(void);
long	sim_time(t_sim *sim);
void	abs_timeout(struct timespec *ts, long ms);
void	sleep_ms(t_sim *sim, long ms);

/* log.c */
int		sim_stopped(t_sim *sim);
void	log_state(t_coder *c, char *msg);
void	log_burnout(t_sim *sim, int id);
void	wake_all(t_sim *sim);
void	sim_stop(t_sim *sim);

/* heap_utils.c / heap.c */
int		heap_init(t_heap *h, int cap);
int		heap_less(t_req *a, t_req *b);
void	heap_swap(t_req *a, t_req *b);
int		heap_push(t_heap *h, long key, long seq, int coder_id);
void	heap_pop(t_heap *h);
t_req	*heap_peek(t_heap *h);

/* dongle.c / pair.c */
int		dongle_init(t_dongle *d);
void	dongle_release(t_sim *sim, int idx);
void	dongle_notify(t_sim *sim, int idx);
int		dongle_enqueue(t_coder *c, t_dongle *d, long key, long ticket);
int		dongle_is_top(t_coder *c, t_dongle *d);
int		acquire_pair(t_coder *c, t_dongle *f, t_dongle *s, long key);

/* coder.c / coder_actions.c */
void	*coder_routine(void *arg);
void	log_compile(t_coder *c);
void	do_compile(t_coder *c);
void	release_both(t_coder *c);

/* monitor.c */
void	*monitor_routine(void *arg);

/* init.c / cleanup.c / run.c */
int		sim_init(t_sim *sim);
void	destroy_dongles(t_sim *sim, int count);
void	destroy_coders(t_sim *sim, int count);
void	sim_destroy(t_sim *sim);
int		sim_run(t_sim *sim);

#endif
