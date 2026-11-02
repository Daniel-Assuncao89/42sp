/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:00:00 by login             #+#    #+#             */
/*   Updated: 2026/10/20 16:00:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	sift_up(t_heap *h, int i)
{
	int	parent;

	while (i > 0)
	{
		parent = (i - 1) / 2;
		if (!heap_less(&h->items[i], &h->items[parent]))
			break ;
		heap_swap(&h->items[i], &h->items[parent]);
		i = parent;
	}
}

static void	sift_down(t_heap *h, int i)
{
	int	left;
	int	right;
	int	min;

	while (1)
	{
		left = 2 * i + 1;
		right = left + 1;
		min = i;
		if (left < h->size && heap_less(&h->items[left], &h->items[min]))
			min = left;
		if (right < h->size && heap_less(&h->items[right], &h->items[min]))
			min = right;
		if (min == i)
			break ;
		heap_swap(&h->items[i], &h->items[min]);
		i = min;
	}
}

int	heap_push(t_heap *h, long key, long seq, int coder_id)
{
	if (h->size == h->cap)
		return (0);
	if (key < 0)
		key = seq;
	h->items[h->size].key = key;
	h->items[h->size].seq = seq;
	h->items[h->size].coder_id = coder_id;
	h->size++;
	sift_up(h, h->size - 1);
	return (1);
}

void	heap_pop(t_heap *h)
{
	if (h->size == 0)
		return ;
	h->size--;
	h->items[0] = h->items[h->size];
	sift_down(h, 0);
}
