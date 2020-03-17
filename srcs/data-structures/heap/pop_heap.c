/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:37:59 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 17:01:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

int	pop_heap(t_heap *heap, void **data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!heap->len)
		return (-1);
	*data = heap->nodes[1].data;
	i = 1;
	while (i < heap->len)
	{
		k = heap->len;
		j = i * 2;
		if (j <= heap->len &&
			heap->nodes[j].priority < heap->nodes[k].priority)
			k = j;
		if (j + 1 <= heap->len &&
			heap->nodes[j + 1].priority < heap->nodes[k].priority)
			k = j + 1;
		heap->nodes[i] = heap->nodes[k];
		i = k;
	}
	heap->len--;
	return (0);
}
