/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by dassunca          #+#    #+#             */
/*   Updated: 2026/11/03 14:05:51 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "codexion.h"

int	heap_init(t_heap *h, int cap)
{
	h->items = malloc(sizeof(t_req) * cap);
	if (!h->items)
		return (1);
	h->size = 0;
	h->cap = cap;
	return (0);
}

int	heap_less(t_req *a, t_req *b)
{
	if (a->key != b->key)
		return (a->key < b->key);
	return (a->seq < b->seq);
}

void	heap_swap(t_req *a, t_req *b)
{
	t_req	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_req	*heap_peek(t_heap *h)
{
	if (h->size == 0)
		return (NULL);
	return (&h->items[0]);
}
